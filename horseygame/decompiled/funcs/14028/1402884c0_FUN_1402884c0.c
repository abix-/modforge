// Address: 0x1402884c0
// Ghidra name: FUN_1402884c0
// ============ 0x1402884c0 FUN_1402884c0 (size=58) ============


undefined8 FUN_1402884c0(longlong param_1)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0xb0))

                    ((longlong *)**(undefined8 **)(param_1 + 0x28),2);

  if (iVar1 < 0) {

    uVar2 = FUN_1402878d0("Stopping the device",iVar1);

    return uVar2;

  }

  return 1;

}




