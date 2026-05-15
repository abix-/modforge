// Address: 0x140287e30
// Ghidra name: FUN_140287e30
// ============ 0x140287e30 FUN_140287e30 (size=172) ============


undefined8 FUN_140287e30(longlong param_1,longlong param_2,undefined2 *param_3)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  undefined8 uVar4;

  

  lVar3 = FUN_140288730(param_3);

  if (lVar3 == 0) {

    uVar4 = FUN_14012e850("Haptic: Unknown effect type.");

  }

  else {

    cVar1 = FUN_1402889b0(param_1,*(undefined8 *)(param_2 + 0x48));

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x90))

                        ((longlong *)**(undefined8 **)(param_1 + 0x28),lVar3,

                         *(longlong *)(param_2 + 0x48),*(longlong *)(param_2 + 0x48) + 0x50,0);

      if (-1 < iVar2) {

        return 1;

      }

      FUN_1402878d0("Unable to create effect",iVar2);

    }

    FUN_140288830(*(undefined8 *)(param_2 + 0x48),*param_3);

    uVar4 = 0;

  }

  return uVar4;

}




