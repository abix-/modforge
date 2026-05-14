// Address: 0x1402151a0
// Ghidra name: FUN_1402151a0
// ============ 0x1402151a0 FUN_1402151a0 (size=84) ============


undefined8 FUN_1402151a0(longlong param_1)



{

  longlong *plVar1;

  int iVar2;

  undefined4 uVar3;

  

  if (*(longlong *)(*(longlong *)(param_1 + 200) + 0x18) != 0) {

    iVar2 = FUN_140138fe0(*(longlong *)(param_1 + 200) + 0x40);

    if (iVar2 == 0) {

      plVar1 = *(longlong **)(*(longlong *)(param_1 + 200) + 0x18);

      uVar3 = (**(code **)(*plVar1 + 0x20))(plVar1,*(undefined4 *)(param_1 + 0x84),0);

      FUN_1402156d0(param_1,uVar3);

    }

  }

  return 1;

}




