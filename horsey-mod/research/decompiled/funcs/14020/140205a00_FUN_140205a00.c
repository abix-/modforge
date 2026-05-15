// Address: 0x140205a00
// Ghidra name: FUN_140205a00
// ============ 0x140205a00 FUN_140205a00 (size=449) ============


undefined8

FUN_140205a00(undefined4 *param_1,int *param_2,int param_3,int param_4,int param_5,

             undefined8 param_6,undefined4 param_7)



{

  bool bVar1;

  char cVar2;

  longlong lVar3;

  undefined8 uVar4;

  int local_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  

  if ((param_3 != param_1[2]) && (*(longlong *)(param_1 + 0x14) != 0)) {

    FUN_140146010();

    *(undefined8 *)(param_1 + 0x14) = 0;

  }

  bVar1 = false;

  if ((((*param_2 != 0) || (param_2[1] != 0)) || (param_2[2] < (int)param_1[3])) ||

     (((param_2[3] < (int)param_1[4] || (param_2[2] != param_4)) || (param_2[3] != param_5)))) {

    bVar1 = true;

    if (*(longlong *)(param_1 + 0x14) == 0) {

      lVar3 = FUN_140145bc0(param_4,param_5,param_3,param_6,param_7);

      *(longlong *)(param_1 + 0x14) = lVar3;

      if (lVar3 == 0) {

        return 0;

      }

      param_1[2] = param_3;

    }

    else {

      *(int *)(*(longlong *)(param_1 + 0x14) + 8) = param_4;

      *(int *)(*(longlong *)(param_1 + 0x14) + 0xc) = param_5;

      *(undefined8 *)(*(longlong *)(param_1 + 0x14) + 0x18) = param_6;

      *(undefined4 *)(*(longlong *)(param_1 + 0x14) + 0x10) = param_7;

    }

    lVar3 = *(longlong *)(param_1 + 0x12);

    if (lVar3 == 0) {

      lVar3 = FUN_140145e60(param_1[3],param_1[4],param_3);

      *(longlong *)(param_1 + 0x12) = lVar3;

      if (lVar3 == 0) {

        return 0;

      }

    }

    param_6 = *(undefined8 *)(lVar3 + 0x18);

    param_7 = *(undefined4 *)(lVar3 + 0x10);

  }

  cVar2 = FUN_140144d60(param_1[3],param_1[4],*param_1,param_1[1],0,*(undefined8 *)(param_1 + 0xc),

                        param_1[8],param_3,0x120005a0,0,param_6,param_7);

  if (cVar2 == '\0') {

    return 0;

  }

  if (!bVar1) {

    return 1;

  }

  local_38 = *param_2;

  iStack_34 = param_2[1];

  iStack_30 = param_2[2];

  iStack_2c = param_2[3];

  uVar4 = FUN_140199be0(*(undefined8 *)(param_1 + 0x12),&local_38,*(undefined8 *)(param_1 + 0x14),0,

                        0);

  return uVar4;

}




