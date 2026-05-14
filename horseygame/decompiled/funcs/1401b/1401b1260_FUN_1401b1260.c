// Address: 0x1401b1260
// Ghidra name: FUN_1401b1260
// ============ 0x1401b1260 FUN_1401b1260 (size=101) ============


void FUN_1401b1260(longlong param_1,longlong *param_2,undefined4 param_3)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  lVar2 = *param_2;

  FUN_1401b37d0(lVar1,param_1);

  (**(code **)(lVar1 + 0xa88))

            (*(undefined8 *)(param_1 + 0x118),*(undefined8 *)(lVar2 + 0x10),param_3);

  FUN_1401bd730(param_1,lVar2);

  return;

}




