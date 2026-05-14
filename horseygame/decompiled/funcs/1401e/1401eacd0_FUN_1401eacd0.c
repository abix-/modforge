// Address: 0x1401eacd0
// Ghidra name: FUN_1401eacd0
// ============ 0x1401eacd0 FUN_1401eacd0 (size=328) ============


undefined8 FUN_1401eacd0(longlong param_1,undefined8 param_2,ulonglong param_3)



{

  longlong lVar1;

  longlong *plVar2;

  int iVar3;

  undefined8 uVar4;

  longlong lVar5;

  longlong lVar6;

  undefined8 local_res8;

  undefined8 local_38;

  undefined8 local_30;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  lVar6 = (longlong)*(int *)(lVar1 + 0x4234c);

  local_res8 = 0;

  local_38 = 0;

  local_30 = 0;

  if (param_3 != 0) {

    if ((*(char *)(lVar1 + 0x42350) != '\0') && (iVar3 = FUN_1401e82f0(lVar1), iVar3 < 0)) {

      uVar4 = FUN_14012e850("Failed to issue intermediate batch");

      return uVar4;

    }

    lVar5 = lVar6 * 0x20;

    if (*(ulonglong *)(lVar5 + 0x128 + lVar1) < param_3) {

      FUN_1401e7830(lVar1,lVar6,param_3);

    }

    plVar2 = *(longlong **)(lVar5 + 0x110 + lVar1);

    iVar3 = (**(code **)(*plVar2 + 0x40))(plVar2,0,&local_38,&local_res8);

    if (iVar3 < 0) {

      uVar4 = FUN_1401a9ef0("ID3D12Resource::Map [vertex buffer]",iVar3);

      return uVar4;

    }

    FUN_1402f8e20(local_res8,param_2,param_3);

    (**(code **)(*plVar2 + 0x48))(plVar2,0,0);

    *(int *)((lVar6 + 9) * 0x20 + lVar1) = (int)param_3;

    (**(code **)(**(longlong **)(lVar1 + 0x48) + 0x160))

              (*(longlong **)(lVar1 + 0x48),0,1,lVar1 + 0x118 + lVar5);

    *(int *)(lVar1 + 0x4234c) = *(int *)(lVar1 + 0x4234c) + 1;

    if (0xff < *(int *)(lVar1 + 0x4234c)) {

      *(undefined4 *)(lVar1 + 0x4234c) = 0;

      *(undefined1 *)(lVar1 + 0x42350) = 1;

    }

  }

  return 1;

}




