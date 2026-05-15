// Address: 0x140100e30
// Ghidra name: FUN_140100e30
// ============ 0x140100e30 FUN_140100e30 (size=379) ============


void FUN_140100e30(longlong param_1,longlong param_2,undefined8 param_3)



{

  float fVar1;

  longlong lVar2;

  longlong lVar3;

  int *piVar4;

  undefined8 uVar5;

  int iVar6;

  int *piVar7;

  undefined4 uVar8;

  undefined8 local_res8;

  longlong local_res10;

  

  local_res8 = param_3;

  FUN_1400bcaf0(param_2);

  *(undefined1 *)(param_2 + 0x204) = 0;

  if ((*(char *)(param_2 + 0x206) != '\0') &&

     (*(int *)(param_2 + 0x1fc) < *(int *)(param_2 + 0x200))) {

    *(int *)(param_2 + 0x1fc) = *(int *)(param_2 + 0x1fc) + 1;

  }

  local_res10 = FUN_1402c704c(200);

  if (local_res10 == 0) {

    lVar2 = 0;

  }

  else {

    lVar2 = FUN_140080680(local_res10);

  }

  *(undefined4 *)(lVar2 + 0x28) = (undefined4)local_res8;

  *(undefined4 *)(lVar2 + 0x2c) = local_res8._4_4_;

  fVar1 = DAT_1403033ac;

  uVar8 = FUN_1400c5f70((undefined4)local_res8,DAT_1403033ac,

                        (float)(*(int *)(param_1 + 0x278) + -2) * DAT_1403033ac);

  *(undefined4 *)(lVar2 + 0x28) = uVar8;

  uVar8 = FUN_1400c5f70(*(undefined4 *)(lVar2 + 0x2c),fVar1,

                        (float)(*(int *)(param_1 + 0x27c) + -2) * fVar1);

  *(undefined4 *)(lVar2 + 0x2c) = uVar8;

  FUN_140080730(lVar2,param_2,1,0);

  if (*(int *)(param_2 + 0x1f8) != -1) {

    lVar3 = FUN_1400c7520();

    *(undefined1 *)(lVar3 + 0x40) = 0;

    piVar4 = (int *)FUN_1400c7520(*(undefined4 *)(param_2 + 0x1f8));

    piVar7 = piVar4;

    if (0xf < *(ulonglong *)(piVar4 + 6)) {

      piVar7 = *(int **)piVar4;

    }

    if (*(longlong *)(piVar4 + 4) == 5) {

      iVar6 = *piVar7 + -0x73726f48;

      if (iVar6 == 0) {

        iVar6 = *(byte *)(piVar7 + 1) - 0x65;

      }

      if (iVar6 == 0) {

        uVar5 = FUN_1400c7520(*(undefined4 *)(param_2 + 0x1f8));

        FUN_140027f50(uVar5,&DAT_14039bcb9,0);

      }

    }

  }

  FUN_140102b40(param_1,lVar2,0x24,0);

  local_res8 = lVar2;

  FUN_14003e600(param_1 + 0xb8,&local_res8);

  return;

}




