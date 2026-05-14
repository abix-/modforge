// Address: 0x1401e49a0
// Ghidra name: FUN_1401e49a0
// ============ 0x1401e49a0 FUN_1401e49a0 (size=676) ============


undefined8

FUN_1401e49a0(longlong param_1,longlong *param_2,int param_3,undefined4 param_4,undefined4 param_5,

             uint param_6,uint param_7,longlong param_8,uint param_9)



{

  int iVar1;

  uint uVar2;

  undefined8 uVar3;

  uint uVar4;

  uint uVar5;

  ulonglong uVar6;

  longlong lVar7;

  bool bVar8;

  longlong *plVar9;

  longlong *local_88 [2];

  longlong local_78;

  uint local_70;

  uint local_68;

  uint local_64;

  int local_58;

  undefined8 local_4c;

  undefined8 local_44;

  

  (**(code **)(*param_2 + 0x50))(param_2,&local_68);

  uVar6 = (ulonglong)param_7;

  local_68 = param_6;

  local_64 = param_7;

  local_4c = 3;

  local_44 = 0x10000;

  if (local_58 - 0x67U < 2) {

    local_68 = param_6 + 1 & 0xfffffffe;

    local_64 = param_7 + 1 & 0xfffffffe;

  }

  iVar1 = (**(code **)(**(longlong **)(param_1 + 0x20) + 0x28))

                    (*(longlong **)(param_1 + 0x20),&local_68,0,local_88);

  if (iVar1 < 0) {

    uVar3 = FUN_1401a9ef0("ID3D11Device1::CreateTexture2D [create staging texture]",iVar1);

    return uVar3;

  }

  plVar9 = &local_78;

  iVar1 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x70))

                    (*(longlong **)(param_1 + 0x28),local_88[0],0,2,0,plVar9);

  if (iVar1 < 0) {

    if (local_88[0] != (longlong *)0x0) {

      (**(code **)(*local_88[0] + 0x10))();

      local_88[0] = (longlong *)0x0;

    }

    uVar3 = FUN_1401a9ef0("ID3D11DeviceContext1::Map [map staging texture]",iVar1);

    return uVar3;

  }

  param_6 = param_3 * param_6;

  if (param_6 == param_9) {

    bVar8 = false;

    if (param_6 == local_70) {

      FUN_1402f8e20(local_78,param_8,(ulonglong)param_6 * (longlong)(int)param_7);

      goto LAB_1401e4b46;

    }

  }

  else {

    if (param_9 <= param_6) {

      param_6 = param_9;

    }

    bVar8 = param_6 == local_70;

  }

  if (local_70 <= param_6 && !bVar8) {

    param_6 = local_70;

  }

  lVar7 = local_78;

  if (0 < (int)param_7) {

    do {

      FUN_1402f8e20(lVar7,param_8,param_6);

      param_8 = param_8 + (int)param_9;

      uVar6 = uVar6 - 1;

      lVar7 = lVar7 + (ulonglong)local_70;

    } while (uVar6 != 0);

  }

LAB_1401e4b46:

  if (local_58 - 0x67U < 2) {

    uVar2 = (int)(param_7 + 1) / 2;

    if (local_58 == 0x68) {

      uVar4 = param_6 + 3 & 0xfffffffc;

      uVar5 = param_9 + 3 & 0xfffffffc;

    }

    else {

      uVar4 = param_6 + 1 & 0xfffffffe;

      uVar5 = param_9 + 1 & 0xfffffffe;

    }

    lVar7 = (ulonglong)(local_70 * local_64) + local_78;

    if (0 < (int)uVar2) {

      uVar6 = (ulonglong)uVar2;

      do {

        FUN_1402f8e20(lVar7,param_8,uVar4);

        param_8 = param_8 + (int)uVar5;

        lVar7 = lVar7 + (ulonglong)local_70;

        uVar6 = uVar6 - 1;

      } while (uVar6 != 0);

    }

  }

  (**(code **)(**(longlong **)(param_1 + 0x28) + 0x78))

            (*(longlong **)(param_1 + 0x28),local_88[0],0);

  (**(code **)(**(longlong **)(param_1 + 0x28) + 0x170))

            (*(longlong **)(param_1 + 0x28),param_2,0,param_4,param_5,

             (ulonglong)plVar9 & 0xffffffff00000000,local_88[0],0,0);

  if (local_88[0] != (longlong *)0x0) {

    (**(code **)(*local_88[0] + 0x10))();

  }

  return 1;

}




