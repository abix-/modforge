// Address: 0x140222e50
// Ghidra name: FUN_140222e50
// ============ 0x140222e50 FUN_140222e50 (size=54) ============


undefined8 FUN_140222e50(longlong param_1,undefined4 *param_2)



{

  code *pcVar1;

  undefined4 uVar2;

  undefined8 uVar3;

  

  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x688) + 0x50);

  if (pcVar1 != (code *)0x0) {

    uVar2 = (*pcVar1)();

    *param_2 = uVar2;

    return 1;

  }

  uVar3 = FUN_14012e850("That operation is not supported");

  return uVar3;

}




