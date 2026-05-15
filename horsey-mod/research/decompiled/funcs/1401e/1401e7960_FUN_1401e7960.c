// Address: 0x1401e7960
// Ghidra name: FUN_1401e7960
// ============ 0x1401e7960 FUN_1401e7960 (size=717) ============


ulonglong FUN_1401e7960(longlong param_1)



{

  longlong lVar1;

  longlong *plVar2;

  undefined4 uVar3;

  int iVar4;

  uint uVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  longlong *plVar8;

  undefined4 local_res8 [2];

  undefined4 local_res10 [2];

  longlong local_res18;

  ulonglong uVar9;

  undefined4 local_48;

  undefined4 local_44;

  undefined8 local_40;

  undefined8 uStack_38;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  FUN_1401e82f0(lVar1);

  uVar7 = 0;

  uVar9 = 0;

  (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x170))(*(longlong **)(lVar1 + 0x48),0,0,0,0);

  plVar8 = (longlong *)(lVar1 + 0xb0);

  if ((longlong *)*plVar8 != (longlong *)0x0) {

    (**(code **)(*(longlong *)*plVar8 + 0x10))();

    *plVar8 = 0;

  }

  if (*(longlong **)(lVar1 + 0xb8) != (longlong *)0x0) {

    (**(code **)(**(longlong **)(lVar1 + 0xb8) + 0x10))();

    *(undefined8 *)(lVar1 + 0xb8) = 0;

  }

  FUN_14016ebe0(*(undefined8 *)(param_1 + 0x118),local_res10,local_res8);

  uVar3 = FUN_14000c580();

  *(undefined4 *)(lVar1 + 0x422a8) = uVar3;

  iVar4 = FUN_1401e2710(uVar3);

  uVar3 = local_res10[0];

  if (iVar4 != 0) {

    local_res10[0] = local_res8[0];

    local_res8[0] = uVar3;

  }

  plVar2 = *(longlong **)(lVar1 + 0x28);

  if (plVar2 == (longlong *)0x0) {

    uVar9 = FUN_1401e6f90(param_1);

    if ((int)uVar9 < 0) {

      return uVar9;

    }

    if (*(longlong *)(lVar1 + 0x28) == 0) {

      return uVar9;

    }

  }

  else {

    uVar5 = (**(code **)(*plVar2 + 0x68))

                      (plVar2,0,local_res10[0],local_res8[0],uVar9 & 0xffffffff00000000,

                       *(undefined4 *)(lVar1 + 0x54));

    if ((int)uVar5 < 0) {

      FUN_1401a9ef0("IDXGISwapChain::ResizeBuffers",uVar5);

      return (ulonglong)uVar5;

    }

  }

  iVar4 = FUN_1401a9950();

  if ((iVar4 != 0) && (*(int *)(lVar1 + 0x50) == 3)) {

    uVar5 = (**(code **)(**(longlong **)(lVar1 + 0x28) + 0xd8))

                      (*(longlong **)(lVar1 + 0x28),*(undefined4 *)(lVar1 + 0x422a8));

    if ((int)uVar5 < 0) {

      FUN_1401a9ef0("IDXGISwapChain4::SetRotation",uVar5);

      return (ulonglong)uVar5;

    }

  }

  do {

    uVar5 = (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x48))

                      (*(longlong **)(lVar1 + 0x28),uVar7,&DAT_14034bc60,lVar1 + (uVar7 + 0x16) * 8)

    ;

    uVar9 = (ulonglong)uVar5;

    if ((int)uVar5 < 0) {

      FUN_1401a9ef0("IDXGISwapChain4::GetBuffer",uVar9);

      return uVar9;

    }

    local_40 = 0;

    uStack_38 = 0;

    local_48 = *(undefined4 *)(lVar1 + 0x60);

    local_44 = 4;

    local_res18 = 0;

    (**(code **)(**(longlong **)(lVar1 + 0x68) + 0x48))(*(longlong **)(lVar1 + 0x68),&local_res18);

    local_res18 = local_res18 + (ulonglong)(uint)((int)uVar7 * *(int *)(lVar1 + 0x70));

    (**(code **)(**(longlong **)(lVar1 + 0x30) + 0xa0))

              (*(longlong **)(lVar1 + 0x30),*plVar8,&local_48);

    uVar5 = (int)uVar7 + 1;

    uVar7 = (ulonglong)uVar5;

    plVar8 = plVar8 + 1;

  } while ((int)uVar5 < 2);

  uVar3 = (**(code **)(**(longlong **)(lVar1 + 0x28) + 0x120))();

  *(undefined4 *)(lVar1 + 200) = uVar3;

  uVar6 = FUN_1401e7ec0(param_1);

  *(undefined8 *)(lVar1 + 0x422b8) = uVar6;

  (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x170))

            (*(longlong **)(lVar1 + 0x48),1,lVar1 + 0x422b8,0,0);

  FUN_1401ea070(lVar1,*(undefined8 *)(lVar1 + 0xb0 + (longlong)*(int *)(lVar1 + 200) * 8),0,4);

  *(undefined1 *)(lVar1 + 0x42308) = 1;

  return uVar9;

}




