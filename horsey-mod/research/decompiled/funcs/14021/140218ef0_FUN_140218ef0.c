// Address: 0x140218ef0
// Ghidra name: FUN_140218ef0
// ============ 0x140218ef0 FUN_140218ef0 (size=38) ============


undefined8 FUN_140218ef0(longlong param_1,longlong param_2)



{

  longlong lVar1;

  

  lVar1 = *(longlong *)(param_1 + 0x690);

  if ((lVar1 != 0) && (param_2 != 0)) {

    (**(code **)(lVar1 + 0x70))(*(undefined8 *)(lVar1 + 0x10));

  }

  return 1;

}




