// Address: 0x14021bc60
// Ghidra name: FUN_14021bc60
// ============ 0x14021bc60 FUN_14021bc60 (size=510) ============


undefined1 FUN_14021bc60(longlong *param_1)



{

  undefined1 uVar1;

  int iVar2;

  undefined4 uVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  undefined8 *puVar7;

  undefined4 uVar8;

  BSTR local_res8;

  undefined1 local_28 [16];

  undefined1 local_18 [16];

  

  local_res8 = (BSTR)0x0;

  iVar2 = (**(code **)(*param_1 + 0x18))(param_1,local_18);

  if (iVar2 < 0) {

    uVar1 = FUN_1401a9ef0("Couldn\'t get sensor ID",iVar2);

    return uVar1;

  }

  iVar2 = (**(code **)(*param_1 + 0x28))(param_1,local_28);

  if (iVar2 < 0) {

    uVar1 = FUN_1401a9ef0("Couldn\'t get sensor type",iVar2);

    return uVar1;

  }

  iVar2 = FUN_1401a98e0(local_28,&DAT_140355250);

  if (iVar2 == 0) {

    iVar2 = FUN_1401a98e0(local_28,&DAT_140355260);

    if (iVar2 == 0) {

      uVar1 = FUN_14012e850("Unknown sensor type");

      return uVar1;

    }

    uVar8 = 2;

  }

  else {

    uVar8 = 1;

  }

  iVar2 = (**(code **)(*param_1 + 0x30))(param_1,&local_res8);

  if ((iVar2 < 0) || (local_res8 == (BSTR)0x0)) {

    lVar4 = FUN_14012f0d0("Unknown Sensor");

  }

  else {

    lVar4 = FUN_14012fd40();

    lVar4 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_res8,lVar4 * 2 + 2);

  }

  if (local_res8 != (BSTR)0x0) {

    SysFreeString(local_res8);

  }

  if (lVar4 == 0) {

    return false;

  }

  FUN_140177410();

  lVar5 = FUN_140184230(DAT_1403fdb98,(longlong)(DAT_1403fdb90 + 1) * 0x38);

  if (lVar5 != 0) {

    (**(code **)(*param_1 + 8))(param_1);

    (**(code **)(*param_1 + 0x88))(param_1,&PTR_PTR_1403e5448);

    lVar6 = (longlong)DAT_1403fdb90;

    DAT_1403fdb90 = DAT_1403fdb90 + 1;

    puVar7 = (undefined8 *)(lVar5 + lVar6 * 0x38);

    DAT_1403fdb98 = lVar5;

    *puVar7 = 0;

    puVar7[1] = 0;

    puVar7[2] = 0;

    puVar7[3] = 0;

    puVar7[4] = 0;

    puVar7[5] = 0;

    puVar7[6] = 0;

    uVar3 = FUN_1401aa810();

    *(undefined4 *)puVar7 = uVar3;

    puVar7[1] = param_1;

    *(undefined4 *)(puVar7 + 5) = uVar8;

    puVar7[4] = lVar4;

    FUN_140177750();

  }

  else {

    FUN_140177750();

    FUN_1401841e0(lVar4);

  }

  return lVar5 != 0;

}




