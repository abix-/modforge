// Address: 0x1401723f0
// Ghidra name: FUN_1401723f0
// ============ 0x1401723f0 FUN_1401723f0 (size=67) ============


uint FUN_1401723f0(undefined8 param_1,undefined8 param_2,undefined4 param_3)



{

  undefined4 uVar1;

  uint uVar2;

  longlong *plVar3;

  

  uVar1 = FUN_14016ea50(param_2);

  plVar3 = (longlong *)FUN_140174d30(uVar1,"SDL.internal.window.texturedata",0);

  if ((plVar3 != (longlong *)0x0) && (*plVar3 != 0)) {

    uVar2 = FUN_140154cf0(*plVar3,param_3);

    return uVar2;

  }

  return (uint)plVar3 & 0xffffff00;

}




