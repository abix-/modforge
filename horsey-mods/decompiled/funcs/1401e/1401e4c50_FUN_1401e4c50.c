// Address: 0x1401e4c50
// Ghidra name: FUN_1401e4c50
// ============ 0x1401e4c50 FUN_1401e4c50 (size=810) ============


undefined8

FUN_1401e4c50(longlong param_1,uint *param_2,undefined4 *param_3,longlong param_4,uint param_5,

             longlong param_6,int param_7)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  undefined8 uVar6;

  uint uVar7;

  longlong lVar8;

  ulonglong uVar9;

  uint uVar10;

  bool bVar11;

  longlong *local_res10;

  undefined4 *local_res18;

  longlong *plVar12;

  longlong local_78;

  uint local_70;

  uint local_68;

  uint local_64;

  int local_58;

  undefined8 local_4c;

  undefined8 local_44;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  uVar10 = *param_2;

  lVar2 = *(longlong *)(param_2 + 0x4e);

  if ((uVar10 == 0) || ((uVar10 & 0xf0000000) == 0x10000000)) {

    uVar10 = uVar10 & 0xff;

  }

  else if ((((uVar10 == 0x32595559) || (uVar10 == 0x59565955)) || (uVar10 == 0x55595659)) ||

          (uVar10 == 0x30313050)) {

    uVar10 = 2;

  }

  else {

    uVar10 = 1;

  }

  local_res18 = param_3;

  if (lVar2 == 0) {

    uVar6 = FUN_14012e850("Texture is not currently available");

    return uVar6;

  }

  uVar7 = param_3[2];

  uVar5 = param_3[3];

  uVar9 = (ulonglong)uVar5;

  (**(code **)(**(longlong **)(lVar2 + 8) + 0x50))(*(longlong **)(lVar2 + 8),&local_68);

  local_4c = 3;

  local_44 = 0x10000;

  local_68 = uVar7;

  local_64 = uVar5;

  if (local_58 - 0x67U < 2) {

    local_68 = uVar7 + 1 & 0xfffffffe;

    local_64 = uVar5 + 1 & 0xfffffffe;

  }

  iVar3 = (**(code **)(**(longlong **)(lVar1 + 0x20) + 0x28))

                    (*(longlong **)(lVar1 + 0x20),&local_68,0,&local_res10);

  if (iVar3 < 0) {

    uVar6 = FUN_1401a9ef0("ID3D11Device1::CreateTexture2D [create staging texture]",iVar3);

    return uVar6;

  }

  plVar12 = &local_78;

  iVar3 = (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x70))

                    (*(longlong **)(lVar1 + 0x28),local_res10,0,2,0,plVar12);

  if (iVar3 < 0) {

    if (local_res10 != (longlong *)0x0) {

      (**(code **)(*local_res10 + 0x10))();

      local_res10 = (longlong *)0x0;

    }

    uVar6 = FUN_1401a9ef0("ID3D11DeviceContext1::Map [map staging texture]",iVar3);

    return uVar6;

  }

  uVar4 = uVar7 * uVar10;

  if (uVar4 == param_5) {

    bVar11 = false;

    if (uVar4 == local_70) {

      FUN_1402f8e20(local_78,param_4,(ulonglong)uVar4 * (longlong)(int)uVar5);

      goto LAB_1401e4e61;

    }

  }

  else {

    if (param_5 <= uVar4) {

      uVar4 = param_5;

    }

    bVar11 = uVar4 == local_70;

  }

  if (local_70 <= uVar4 && !bVar11) {

    uVar4 = local_70;

  }

  lVar8 = local_78;

  if (0 < (int)uVar5) {

    do {

      FUN_1402f8e20(lVar8,param_4,uVar4);

      param_4 = param_4 + (int)param_5;

      uVar9 = uVar9 - 1;

      lVar8 = lVar8 + (ulonglong)local_70;

    } while (uVar9 != 0);

  }

LAB_1401e4e61:

  uVar5 = (int)(uVar5 + 1) / 2;

  uVar9 = (ulonglong)uVar5;

  uVar10 = ((int)(uVar7 + 1) / 2) * uVar10 * 2;

  if (local_58 == 0x68) {

    uVar10 = uVar10 + 3 & 0xfffffffc;

    uVar7 = param_7 + 3U & 0xfffffffc;

  }

  else {

    uVar7 = param_7 + 1U & 0xfffffffe;

  }

  lVar8 = (ulonglong)(local_70 * local_64) + local_78;

  if (0 < (int)uVar5) {

    do {

      FUN_1402f8e20(lVar8,param_6,uVar10);

      param_6 = param_6 + (int)uVar7;

      lVar8 = lVar8 + (ulonglong)local_70;

      uVar9 = uVar9 - 1;

    } while (uVar9 != 0);

  }

  (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x78))(*(longlong **)(lVar1 + 0x28),local_res10,0);

  (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x170))

            (*(longlong **)(lVar1 + 0x28),*(undefined8 *)(lVar2 + 8),0,*local_res18,local_res18[1],

             (ulonglong)plVar12 & 0xffffffff00000000,local_res10,0,0);

  if (local_res10 != (longlong *)0x0) {

    (**(code **)(*local_res10 + 0x10))();

  }

  return 1;

}




