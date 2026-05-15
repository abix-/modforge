// Address: 0x1401ef800
// Ghidra name: FUN_1401ef800
// ============ 0x1401ef800 FUN_1401ef800 (size=916) ============


undefined8 FUN_1401ef800(longlong param_1,int *param_2,int param_3,longlong param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  code *pcVar8;

  int iVar9;

  char cVar10;

  longlong lVar11;

  

  iVar1 = param_2[0xb];

  if (*(char *)(param_1 + 0x200) != '\0') {

    lVar11 = *(longlong *)(param_1 + 0x220);

    (**(code **)(param_1 + 0x110))(0x1701);

    (**(code **)(param_1 + 0x108))();

    if (lVar11 == 0) {

      iVar9 = (*(int *)(param_1 + 0x22c) - *(int *)(param_1 + 0x210)) - *(int *)(param_1 + 0x208);

    }

    else {

      iVar9 = *(int *)(param_1 + 0x208);

    }

    (**(code **)(param_1 + 0x1b0))

              (*(undefined4 *)(param_1 + 0x204),iVar9,*(undefined4 *)(param_1 + 0x20c),

               *(undefined4 *)(param_1 + 0x210));

    if (*(int *)(param_1 + 0x20c) != 0) {

      iVar9 = *(int *)(param_1 + 0x210);

      if (iVar9 != 0) {

        iVar2 = iVar9;

        if (lVar11 == 0) {

          iVar2 = 0;

        }

        iVar3 = 0;

        if (lVar11 == 0) {

          iVar3 = iVar9;

        }

        (**(code **)(param_1 + 0x118))

                  (iVar9,(double)*(int *)(param_1 + 0x20c),(double)iVar3,(double)iVar2,0,

                   DAT_140304b90);

      }

    }

    (**(code **)(param_1 + 0x110))(0x1700);

    *(undefined1 *)(param_1 + 0x200) = 0;

  }

  if (*(char *)(param_1 + 0x250) != '\0') {

    if (*(char *)(param_1 + 0x251) == '\0') {

      pcVar8 = *(code **)(param_1 + 0x98);

    }

    else {

      pcVar8 = *(code **)(param_1 + 0xb8);

    }

    (*pcVar8)(0xc11);

    *(undefined1 *)(param_1 + 0x250) = 0;

  }

  if ((*(char *)(param_1 + 0x251) != '\0') && (*(char *)(param_1 + 0x252) != '\0')) {

    if (*(longlong *)(param_1 + 0x220) == 0) {

      iVar9 = ((*(int *)(param_1 + 0x22c) - *(int *)(param_1 + 600)) - *(int *)(param_1 + 0x260)) -

              *(int *)(param_1 + 0x208);

    }

    else {

      iVar9 = *(int *)(param_1 + 600) + *(int *)(param_1 + 0x208);

    }

    (**(code **)(param_1 + 0x158))

              (*(int *)(param_1 + 0x254) + *(int *)(param_1 + 0x204),iVar9,

               *(undefined4 *)(param_1 + 0x25c),*(undefined4 *)(param_1 + 0x260));

    *(undefined1 *)(param_1 + 0x252) = 0;

  }

  if (iVar1 != *(int *)(param_1 + 0x230)) {

    if (iVar1 == 0) {

      (**(code **)(param_1 + 0x98))();

    }

    else {

      (**(code **)(param_1 + 0xb8))(0xbe2);

      uVar4 = FUN_14014dea0(iVar1);

      uVar4 = FUN_1401ef410(uVar4);

      uVar5 = FUN_14014dee0(iVar1);

      uVar5 = FUN_1401ef410(uVar5);

      uVar6 = FUN_14014dec0(iVar1);

      uVar6 = FUN_1401ef410(uVar6);

      uVar7 = FUN_14014df00(iVar1);

      uVar7 = FUN_1401ef410(uVar7);

      (**(code **)(param_1 + 0x50))(uVar7,uVar6,uVar5,uVar4);

      uVar4 = FUN_14014de80(iVar1);

      uVar4 = FUN_1401ef3d0(uVar4);

      (**(code **)(param_1 + 0x48))(uVar4);

    }

    *(int *)(param_1 + 0x230) = iVar1;

  }

  if ((*(longlong *)(param_1 + 0x1f8) != 0) &&

     ((param_3 != *(int *)(param_1 + 0x234) || (param_4 != *(longlong *)(param_1 + 0x248))))) {

    FUN_140240d00(*(longlong *)(param_1 + 0x1f8),param_3,param_4);

    *(int *)(param_1 + 0x234) = param_3;

    *(longlong *)(param_1 + 0x248) = param_4;

  }

  if (*(char *)(param_1 + 0x265) == '\0') {

    lVar11 = *(longlong *)(param_2 + 0xc);

    if ((lVar11 != 0) == (bool)*(char *)(param_1 + 0x264)) goto LAB_1401eface;

  }

  lVar11 = *(longlong *)(param_2 + 0xc);

  if (lVar11 != 0) {

    (**(code **)(param_1 + 0xb8))(*(undefined4 *)(param_1 + 0x28));

  }

  else {

    (**(code **)(param_1 + 0x98))();

  }

  *(bool *)(param_1 + 0x264) = lVar11 != 0;

  *(undefined1 *)(param_1 + 0x265) = 0;

  lVar11 = *(longlong *)(param_2 + 0xc);

LAB_1401eface:

  iVar1 = *param_2;

  if ((iVar1 == 5) || ((iVar1 - 6U & 0xfffffffb) == 0)) {

    cVar10 = '\x01';

  }

  else {

    cVar10 = '\0';

  }

  if (cVar10 != *(char *)(param_1 + 0x266)) {

    if (cVar10 == '\0') {

      pcVar8 = *(code **)(param_1 + 0xa0);

    }

    else {

      pcVar8 = *(code **)(param_1 + 0xc0);

    }

    (*pcVar8)(0x8074);

    *(char *)(param_1 + 0x266) = cVar10;

  }

  if ((iVar1 == 10) != (bool)*(char *)(param_1 + 0x267)) {

    if (iVar1 == 10) {

      pcVar8 = *(code **)(param_1 + 0xc0);

    }

    else {

      pcVar8 = *(code **)(param_1 + 0xa0);

    }

    (*pcVar8)(0x8076);

    *(bool *)(param_1 + 0x267) = iVar1 == 10;

  }

  if ((lVar11 != 0) != (bool)*(char *)(param_1 + 0x268)) {

    if (lVar11 == 0) {

      pcVar8 = *(code **)(param_1 + 0xa0);

    }

    else {

      pcVar8 = *(code **)(param_1 + 0xc0);

    }

    (*pcVar8)(0x8078);

    *(bool *)(param_1 + 0x268) = lVar11 != 0;

  }

  return 1;

}




