// Address: 0x14020d410
// Ghidra name: FUN_14020d410
// ============ 0x14020d410 FUN_14020d410 (size=851) ============


undefined8 FUN_14020d410(undefined8 param_1,undefined8 param_2,undefined8 *param_3)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  char cVar5;

  int iVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  longlong lVar9;

  longlong lVar10;

  ulonglong uVar11;

  undefined4 *puVar12;

  undefined8 *puVar13;

  undefined8 uVar14;

  char local_res20;

  undefined7 uStackX_21;

  ulonglong uVar15;

  short local_58 [2];

  undefined2 local_54 [2];

  longlong *local_50;

  longlong *local_48;

  longlong *local_40;

  undefined1 local_38 [16];

  

  uVar11 = 0;

  local_50 = (longlong *)0x0;

  FUN_140159d30();

  cVar5 = FUN_140159a90();

  if (cVar5 != '\0') goto LAB_14020d750;

  cVar5 = FUN_140159a50();

  if (cVar5 == '\0') goto LAB_14020d750;

  iVar6 = (**(code **)*param_3)(param_3,&DAT_1403505f8,&local_50);

  if (iVar6 < 0) goto LAB_14020d750;

  local_54[0] = 0;

  uVar8 = 0;

  local_58[0] = 0;

  local_40 = (longlong *)0x0;

  local_48 = (longlong *)0x0;

  uVar14 = 3;

  (**(code **)(*local_50 + 0x50))(local_50,local_54);

  (**(code **)(*local_50 + 0x48))(local_50,local_58);

  iVar6 = (**(code **)*local_50)(local_50,&DAT_140350598,&local_48);

  if (-1 < iVar6) {

    local_res20 = '\0';

    iVar6 = (**(code **)(*local_48 + 0x68))(local_48,&local_res20);

    if (((-1 < iVar6) && (local_res20 != '\0')) && (uVar14 = 5, local_58[0] == 0)) {

      local_54[0] = 0x45e;

      local_58[0] = 0x2a1;

    }

    (**(code **)(*local_48 + 0x10))();

  }

  iVar6 = (**(code **)*local_50)(local_50,&DAT_140350608,&local_40);

  if (iVar6 < 0) {

LAB_14020d5b4:

    uVar11 = FUN_14012f0d0(&DAT_14039bcb9);

  }

  else {

    iVar6 = (**(code **)(*local_40 + 0x40))(local_40,&local_res20);

    if (-1 < iVar6) {

      lVar9 = (*DAT_1403fd298)(CONCAT71(uStackX_21,local_res20),0);

      if (lVar9 != 0) {

        lVar10 = FUN_14012fd40(lVar9);

        uVar11 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",lVar9,lVar10 * 2 + 2);

      }

      (*DAT_1403fd290)(CONCAT71(uStackX_21,local_res20));

    }

    (**(code **)(*local_40 + 0x10))();

    if (uVar11 == 0) goto LAB_14020d5b4;

  }

  cVar5 = FUN_14015ba80(local_54[0],local_58[0],0,uVar11);

  if (cVar5 == '\0') {

    uVar15 = uVar11;

    cVar5 = FUN_1401599b0(&PTR_FUN_1403e4fe0,local_54[0],local_58[0],0,uVar11);

    if (cVar5 != '\0') goto LAB_14020d71b;

    cVar5 = FUN_14020e6a0(local_54[0],local_58[0],uVar11);

    if (cVar5 != '\0') goto LAB_14020d71b;

    lVar9 = FUN_140184230(DAT_1403fd2f8,(longlong)(DAT_1403fd2f0 + 1) * 0x30);

    if (lVar9 == 0) goto LAB_14020d71b;

    puVar13 = (undefined8 *)((longlong)DAT_1403fd2f0 * 0x30 + lVar9);

    uVar7 = FUN_1401aa810();

    if (local_48 != (longlong *)0x0) {

      uVar8 = FUN_14020e470();

    }

    *puVar13 = 0;

    puVar13[1] = 0;

    puVar13[2] = 0;

    puVar13[3] = 0;

    puVar13[4] = 0;

    puVar13[5] = 0;

    *(undefined4 *)puVar13 = uVar7;

    puVar13[1] = local_50;

    puVar13[2] = uVar11;

    puVar12 = (undefined4 *)

              FUN_140157780(local_38,uVar14,local_54[0],local_58[0],uVar15 & 0xffffffffffff0000,0,

                            uVar11,0x77,(char)uVar8);

    uVar1 = *puVar12;

    uVar2 = puVar12[1];

    uVar3 = puVar12[2];

    uVar4 = puVar12[3];

    *(undefined4 *)(puVar13 + 5) = uVar8;

    *(undefined4 *)(puVar13 + 3) = uVar1;

    *(undefined4 *)((longlong)puVar13 + 0x1c) = uVar2;

    *(undefined4 *)(puVar13 + 4) = uVar3;

    *(undefined4 *)((longlong)puVar13 + 0x24) = uVar4;

    uVar8 = FUN_14020e5a0(local_50,local_54[0],local_58[0]);

    *(undefined4 *)((longlong)puVar13 + 0x2c) = uVar8;

    (**(code **)(*local_50 + 8))();

    DAT_1403fd2f0 = DAT_1403fd2f0 + 1;

    DAT_1403fd2f8 = lVar9;

    FUN_14015a2b0(uVar7);

  }

  else {

LAB_14020d71b:

    FUN_1401841e0(uVar11);

  }

  (**(code **)(*local_50 + 0x10))();

LAB_14020d750:

  FUN_14015bb10();

  return 0;

}




