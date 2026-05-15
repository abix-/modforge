// Address: 0x140181290
// Ghidra name: FUN_140181290
// ============ 0x140181290 FUN_140181290 (size=65) ============


undefined8 FUN_140181290(longlong param_1)



{

  code *pcVar1;

  int iVar2;

  undefined8 uVar3;

  

  pcVar1 = *(code **)(*(longlong *)(param_1 + 0x680) + 0x90);

  if ((pcVar1 != (code *)0x0) && (iVar2 = (*pcVar1)(0xfffffffffffffffc), iVar2 != 0)) {

    return 1;

  }

  uVar3 = FUN_140181240(param_1);

  return uVar3;

}




