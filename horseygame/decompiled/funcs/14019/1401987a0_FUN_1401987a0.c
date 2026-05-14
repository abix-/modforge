// Address: 0x1401987a0
// Ghidra name: FUN_1401987a0
// ============ 0x1401987a0 FUN_1401987a0 (size=56) ============


ulonglong FUN_1401987a0(longlong param_1,longlong param_2,undefined4 param_3)



{

  ulonglong in_RAX;

  undefined8 uVar1;

  ulonglong uVar2;

  

  if ((param_1 != 0) && (param_2 != 0)) {

    uVar1 = (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x30),param_3);

    uVar2 = FUN_140197e70(uVar1,param_2);

    return uVar2;

  }

  return in_RAX & 0xffffffffffffff00;

}




