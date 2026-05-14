// Address: 0x1402882f0
// Ghidra name: FUN_1402882f0
// ============ 0x1402882f0 FUN_1402882f0 (size=58) ============


undefined8 FUN_1402882f0(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0xb0))

                    ((longlong *)**(undefined8 **)(param_1 + 0x28),4);

  if (iVar1 < 0) {

    uVar2 = FUN_1402878d0("Pausing the device",iVar1);

    return uVar2;

  }

  return 1;

}




