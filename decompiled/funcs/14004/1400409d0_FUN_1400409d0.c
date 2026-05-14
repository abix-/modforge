// Address: 0x1400409d0
// Ghidra name: FUN_1400409d0
// ============ 0x1400409d0 FUN_1400409d0 (size=326) ============


undefined8 FUN_1400409d0(int param_1,int param_2,int param_3,float param_4,undefined1 param_5)



{

  int iVar1;

  longlong *plVar2;

  int iVar3;

  undefined8 uVar4;

  int local_58;

  undefined4 local_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  undefined8 local_28;

  

  if (((((DAT_1403d9504 == 0) || (DAT_1403ea292 != '\0')) || (DAT_1403ea293 == '\0')) ||

      ((param_1 == -1 ||

       (plVar2 = *(longlong **)(DAT_1403ea2d0 + (longlong)param_1 * 8), plVar2 == (longlong *)0x0)))

      ) || (*plVar2 == 0)) {

    uVar4 = 0xffffffff;

  }

  else {

    if (((int)plVar2[6] != 100) || (*(int *)((longlong)plVar2 + 0x2c) != 100)) {

      iVar1 = *(int *)((longlong)plVar2 + 0x2c);

      iVar3 = FUN_1400c6580(((int)plVar2[6] - iVar1) + 1);

      param_4 = param_4 * (float)(iVar3 + iVar1) * DAT_14039ca0c;

    }

    local_58 = (uint)CONCAT21(local_38._2_2_,param_5) << 8;

    fStack_34 = ((float)param_2 * *(float *)(plVar2 + 5)) / DAT_14039ca5c;

    fStack_30 = (float)(param_3 + 100) / DAT_140304c38;

    local_28 = 0;

    local_38 = local_58;

    fStack_2c = param_4;

    uVar4 = FUN_1400457f0(*plVar2,&local_38);

  }

  return uVar4;

}




