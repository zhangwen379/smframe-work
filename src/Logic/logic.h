#ifndef LOGIC_H
#define LOGIC_H

#include "base.h"
#include <Windows.h>
enum VarID_Logic
{
    VarSM_AllSystem_ID=10000,//max_VarID,
    Var_AllSystem_LastFile_ID,
    VarSM_Ball_ID,
    Var_Ball_PosX_ID,
    Var_Ball_PosY_ID,
    Var_Ball_SpeedX_ID,
    Var_Ball_SpeedY_ID,
    Var_Ball_RangeX_ID,
    Var_Ball_RangeY_ID,
    Var_Ball_Radius_ID,

    VarMsg_Ball_FreshPOS,
    max_Logic_VarID,
};
#endif // LOGIC_H
