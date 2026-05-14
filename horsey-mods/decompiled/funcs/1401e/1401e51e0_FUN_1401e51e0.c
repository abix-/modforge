// Address: 0x1401e51e0
// Ghidra name: FUN_1401e51e0
// ============ 0x1401e51e0 FUN_1401e51e0 (size=418) ============


undefined8 FUN_1401e51e0(longlong param_1,undefined8 param_2,ulonglong param_3)



{

  longlong lVar1;

  longlong lVar2;

  longlong *plVar3;

  int iVar4;

  uint uVar5;

  ulonglong uVar6;

  undefined8 uVar7;

  undefined4 local_res8 [2];

  undefined4 local_res18 [4];

  ulonglong in_stack_ffffffffffffff98;

  undefined8 local_58;

  undefined8 local_50;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined8 local_38;

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  uVar6 = (ulonglong)*(int *)(lVar2 + 0x48c);

  local_res18[0] = 0x20;

  local_res8[0] = 0;

  if (param_3 == 0) goto LAB_1401e536c;

  plVar3 = *(longlong **)(lVar2 + 0x60 + uVar6 * 8);

  lVar1 = lVar2 + uVar6 * 8;

  if (plVar3 == (longlong *)0x0) {

LAB_1401e52b4:

    local_38 = 0;

    local_48 = (undefined4)param_3;

    local_44 = 2;

    local_40 = 1;

    local_3c = 0x10000;

    local_50 = 0;

    local_58 = param_2;

    iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x20) + 0x18))

                      (*(longlong **)(lVar2 + 0x20),&local_48,&local_58,lVar1 + 0x60);

    if (iVar4 < 0) {

      uVar7 = FUN_1401a9ef0("ID3D11Device1::CreateBuffer [vertex buffer]",iVar4);

      return uVar7;

    }

    *(ulonglong *)(lVar2 + (uVar6 + 0x14) * 8) = param_3;

  }

  else {

    if (*(ulonglong *)(lVar2 + 0xa0 + uVar6 * 8) < param_3) {

      (**(code **)(*plVar3 + 0x10))(plVar3);

      *(undefined8 *)(lVar1 + 0x60) = 0;

      goto LAB_1401e52b4;

    }

    iVar4 = (**(code **)(**(longlong **)(lVar2 + 0x28) + 0x70))

                      (*(longlong **)(lVar2 + 0x28),plVar3,0,4,

                       in_stack_ffffffffffffff98 & 0xffffffff00000000,&local_58);

    if (iVar4 < 0) {

      uVar7 = FUN_1401a9ef0("ID3D11DeviceContext1::Map [vertex buffer]",iVar4);

      return uVar7;

    }

    FUN_1402f8e20(local_58,param_2,param_3);

    (**(code **)(**(longlong **)(lVar2 + 0x28) + 0x78))

              (*(longlong **)(lVar2 + 0x28),*(undefined8 *)(lVar1 + 0x60),0);

  }

  (**(code **)(**(longlong **)(lVar2 + 0x28) + 0x90))

            (*(longlong **)(lVar2 + 0x28),0,1,lVar1 + 0x60,local_res18,local_res8);

  uVar5 = *(int *)(lVar2 + 0x48c) + 1;

  uVar6 = (ulonglong)uVar5;

  *(uint *)(lVar2 + 0x48c) = uVar5;

  if (7 < uVar5) {

    *(undefined4 *)(lVar2 + 0x48c) = 0;

  }

LAB_1401e536c:

  return CONCAT71((int7)(uVar6 >> 8),1);

}




