// Address: 0x14016ef40
// Ghidra name: FUN_14016ef40
// ============ 0x14016ef40 FUN_14016ef40 (size=68) ============


uint FUN_14016ef40(undefined8 param_1,undefined8 param_2,undefined8 param_3)



{

  undefined4 uVar1;

  uint uVar2;

  longlong *plVar3;

  

  uVar1 = FUN_14016ea50(param_2);

  plVar3 = (longlong *)FUN_140174d30(uVar1,"SDL.internal.window.texturedata",0);

  if ((plVar3 != (longlong *)0x0) && (*plVar3 != 0)) {

    uVar2 = FUN_14014edc0(*plVar3,param_3);

    return uVar2;

  }

  return (uint)plVar3 & 0xffffff00;

}




