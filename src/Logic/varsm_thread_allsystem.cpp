#include "varsm_thread_allsystem.h"
#include "varstate_work_allsystem.h"
#include <QFile>
#include "makefilepath.h"
#include <QDomDocument>
#include <QDomProcessingInstruction>
#include <QDebug>
#include "varsm_thread_ball.h"
VarSM_Thread_AllSystem m_gAllSystem;
VarSM_Thread_AllSystem::VarSM_Thread_AllSystem()
{
    m_iID=VarSM_AllSystem_ID;
    m_sName=QObject::trUtf8("AllSystem");
}

VarSM_Thread_AllSystem::VarSM_Thread_AllSystem(int iID, const QString &sName)
    :VarSM_Thread(iID, sName)
{
}

VarSM_Thread_AllSystem::~VarSM_Thread_AllSystem()
{
    MVarSM_Thread::iterator ii=m_mVarSM_Thread.begin();
    for(;ii!=m_mVarSM_Thread.end();ii++)
    {
        delete (*ii);
    }
}

VarSM_Thread *VarSM_Thread_AllSystem::get_VarSM_Thread(int iID)
{
    MVarSM_Thread::iterator ii=m_mVarSM_Thread.find(iID);
    VarSM_Thread *pSM=0;
    if(ii!=m_mVarSM_Thread.end())
    {
        pSM=(*ii);
    }
    Q_ASSERT(pSM);
    return pSM;
}

void VarSM_Thread_AllSystem::add_VarSM_Thread(int iID, VarSM_Thread *pSM)
{
    m_mVarSM_Thread[iID]=pSM;
}

VarMsg VarSM_Thread_AllSystem::run()
{
    VarState *pState=get_VarState(m_iStateID);
    Q_ASSERT(pState);
    VarMsg msg= pState->popfront_Msg();
    if(msg.m_iID==0)
    {
        return msg;
    }
    try
    {
        pState->do_Msg(msg);
    }
    catch(QString &s)
    {
         qDebug()<<s;
    }
    return msg;
}

void VarSM_Thread_AllSystem::WriteConfig()
{
    QFile file(MakeFilePath::config("config.xml"));
    bool isOk = file.open(QIODevice::WriteOnly);
    if(true == isOk)
    {
        QDomDocument doc;
        //创建xml头部格式 <?xml version="1.0" encoding="UTF-8"?>
        QDomProcessingInstruction ins;
        ins = doc.createProcessingInstruction("xml","version=\'1.0\' encoding=\'UTF-8\'");
        //追加元素
        doc.appendChild(ins);
        //根节点元素
        QDomElement root = doc.createElement(m_sName);
        root.setAttribute("ID",m_iID);
        doc.appendChild(root);

        m_Variants.WriteConfig(doc,root);
        MVarSM_Thread::iterator ii=m_mVarSM_Thread.begin();
        for(;ii!=m_mVarSM_Thread.end();ii++)
        {
            (*ii)->WriteConfig(doc,root);
        }

        //保存
        QTextStream stream(&file);  //文本流关联文件
        doc.save(stream,4); //4 缩进字符

        file.close();  //关闭文件
    }
}

void VarSM_Thread_AllSystem::ReadConfig()
{
    QFile file(MakeFilePath::config("config.xml"));
    bool isOk = file.open(QIODevice::ReadOnly);
    if(true == isOk)
    {
        //file和文档对象关联
        QDomDocument doc;
        isOk =doc.setContent(&file);
        if(isOk) //如果关联成功
        {
            //获取根节点
            QDomElement root = doc.documentElement();
            file.close();
            QDomNodeList List=root.childNodes();
            int iSizeList=List.size();

            m_Variants.ReadConfig(root);
            int iIndex=m_Variants.m_mVariantMap.size();
            MVarSM_Thread::iterator ii=m_mVarSM_Thread.begin();
            for(;ii!=m_mVarSM_Thread.end();ii++)
            {
                Q_ASSERT(iIndex<iSizeList);UNUSED(iSizeList);
                (*ii)->ReadConfig(List.at(iIndex).toElement());
                iIndex++;
            }
        }
    }
}

void VarSM_Thread_AllSystem::WriteFile()
{
    QString fileName=m_Variants.get_Variant(Var_AllSystem_LastFile_ID)->m_vVar.toString();
    QFile file(MakeFilePath::data(fileName));
    bool isOk = file.open(QIODevice::WriteOnly);
    QDataStream stream(&file);
    if(true == isOk)
    {
        stream<<m_Variants;
        MVarSM_Thread::iterator ii=m_mVarSM_Thread.begin();
        for(;ii!=m_mVarSM_Thread.end();ii++)
        {
            stream<<*(*ii);
        }
    }
}

void VarSM_Thread_AllSystem::ReadFile()
{
    QString fileName=m_Variants.get_Variant(Var_AllSystem_LastFile_ID)->m_vVar.toString();
    QFile file(MakeFilePath::data(fileName));
    bool isOk = file.open(QIODevice::ReadOnly);
    QDataStream stream(&file);
    if(true == isOk)
    {
        stream>>m_Variants;
        MVarSM_Thread::iterator ii=m_mVarSM_Thread.begin();
        for(;ii!=m_mVarSM_Thread.end();ii++)
        {
            stream>>*(*ii);
        }
    }
}

void VarSM_Thread_AllSystem::pushBack_Msg(int iID, const VarMsg &msg)
{
    if(!iID)
    {
        MVarSM_Thread::iterator ii=m_mVarSM_Thread.begin();
        for(;ii!=m_mVarSM_Thread.end();ii++)
        {
            (*ii)->pushBack_Msg(0,msg);
        }
    }
    else
    {
        get_VarSM_Thread(iID)->pushBack_Msg(0,msg);
    }
}

void VarSM_Thread_AllSystem::pushFront_Msg(int iID, const VarMsg &msg)
{
    if(!iID)
    {
        MVarSM_Thread::iterator ii=m_mVarSM_Thread.begin();
        for(;ii!=m_mVarSM_Thread.end();ii++)
        {
            (*ii)->pushFront_Msg(0,msg);
        }
    }
    else
    {
        get_VarSM_Thread(iID)->pushFront_Msg(0,msg);
    }
}


void VarSM_Thread_AllSystem::Init()
{
    m_iStateID=VarState_Work_ID;

    m_mMVarState[VarState_Work_ID]=new VarState_Work_AllSystem(VarState_Work_ID,this);

    add_VarSM_Thread(VarSM_Ball_ID, new VarSM_Thread_Ball(VarSM_Ball_ID,QObject::trUtf8("Ball")));

    m_Variants.add_Variant(Var_AllSystem_LastFile_ID,QObject::trUtf8("LastFile"),QVariant(QString("000.smf")),false,false);
    VarSM_Thread::Init();
}

