// Address: 0x140288370
// Ghidra name: FUN_140288370
// ============ 0x140288370 FUN_140288370 (size=58) ============


undefined8 FUN_140288370(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0xb0))

                    ((longlong *)**(undefined8 **)(param_1 + 0x28),8);

  if (iVar1 < 0) {

    uVar2 = FUN_1402878d0("Pausing the device",iVar1);

    return uVar2;

  }

  return 1;

}




