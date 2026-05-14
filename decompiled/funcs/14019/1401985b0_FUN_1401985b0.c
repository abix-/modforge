// Address: 0x1401985b0
// Ghidra name: FUN_1401985b0
// ============ 0x1401985b0 FUN_1401985b0 (size=53) ============


ulonglong FUN_1401985b0(longlong param_1,longlong param_2)



{

  ulonglong in_RAX;

  undefined8 uVar1;

  ulonglong uVar2;

  

  if ((param_1 != 0) && (param_2 != 0)) {

    uVar1 = (**(code **)(param_1 + 0x10))(*(undefined8 *)(param_1 + 0x30));

    uVar2 = FUN_140197e70(uVar1,param_2);

    return uVar2;

  }

  return in_RAX & 0xffffffffffffff00;

}




