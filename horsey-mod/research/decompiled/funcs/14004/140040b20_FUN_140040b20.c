// Address: 0x140040b20
// Ghidra name: FUN_140040b20
// ============ 0x140040b20 FUN_140040b20 (size=376) ============


undefined8

FUN_140040b20(undefined8 param_1,int param_2,int param_3,int param_4,float param_5,

             undefined1 param_6)



{

  int iVar1;

  longlong lVar2;

  int iVar3;

  longlong *plVar4;

  undefined8 uVar5;

  longlong lVar6;

  int local_48;

  undefined4 local_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  undefined8 local_18;

  

  if (((((DAT_1403d9504 == 0) || (DAT_1403ea292 != '\0')) || (DAT_1403ea293 == '\0')) ||

      ((plVar4 = (longlong *)FUN_140047560(&DAT_1403ea2c0,param_1), param_2 < 0 ||

       (lVar2 = *plVar4, (int)(plVar4[1] - lVar2 >> 6) <= param_2)))) ||

     (lVar6 = (longlong)param_2 * 0x40, *(longlong *)(lVar6 + lVar2) == 0)) {

    uVar5 = 0xffffffff;

  }

  else {

    iVar3 = *(int *)(lVar6 + 0x30 + lVar2);

    if ((iVar3 != 100) || (*(int *)(lVar6 + lVar2 + 0x2c) != 100)) {

      iVar1 = *(int *)(lVar6 + lVar2 + 0x2c);

      iVar3 = FUN_1400c6580((iVar3 - iVar1) + 1);

      param_5 = param_5 * (float)(iVar3 + iVar1) * DAT_14039ca0c;

    }

    local_48 = (uint)CONCAT21(local_28._2_2_,param_6) << 8;

    fStack_24 = ((float)param_3 * *(float *)(lVar6 + 0x28 + *plVar4)) / DAT_14039ca5c;

    fStack_20 = (float)(param_4 + 100) / DAT_140304c38;

    local_18 = 0;

    local_28 = local_48;

    fStack_1c = param_5;

    uVar5 = FUN_1400457f0(*(undefined8 *)(lVar6 + *plVar4),&local_28);

  }

  return uVar5;

}




