// Address: 0x1402238d0
// Ghidra name: FUN_1402238d0
// ============ 0x1402238d0 FUN_1402238d0 (size=48) ============


undefined4 FUN_1402238d0(undefined8 param_1,longlong param_2)



{

  BOOL BVar1;

  undefined4 uVar2;

  

  BVar1 = SwapBuffers(*(HDC *)(*(longlong *)(param_2 + 0x188) + 0x18));

  if (BVar1 == 0) {

    uVar2 = FUN_1401a9ed0("SwapBuffers()");

    return uVar2;

  }

  return 1;

}




