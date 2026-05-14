// Address: 0x140026450
// Ghidra name: FUN_140026450
// ============ 0x140026450 FUN_140026450 (size=205) ============


undefined8 * FUN_140026450(undefined8 param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  

  puVar1 = (undefined8 *)FUN_1402c704c(0xa0);

  puVar1[1] = 0xffffffffffffffff;

  puVar1[2] = 0;

  puVar1[7] = 0;

  puVar1[8] = 0;

  puVar1[9] = 0;

  puVar1[10] = 0xf;

  *(undefined1 *)(puVar1 + 7) = 0;

  puVar1[3] = 0;

  *(undefined4 *)(puVar1 + 4) = 0;

  puVar1[5] = 0;

  puVar1[6] = 0;

  puVar1[0xb] = 0;

  puVar1[0xc] = 0;

  *puVar1 = TiXmlDocument::vftable;

  puVar2 = puVar1 + 0xe;

  *puVar2 = 0;

  puVar1[0xf] = 0;

  puVar1[0x10] = 0;

  puVar1[0x11] = 0xf;

  *(undefined1 *)puVar2 = 0;

  *(undefined8 *)((longlong)puVar1 + 0x94) = 0xffffffffffffffff;

  *(undefined4 *)(puVar1 + 0x12) = 4;

  *(undefined1 *)((longlong)puVar1 + 0x9c) = 0;

  *(undefined1 *)(puVar1 + 0xd) = 0;

  *(undefined4 *)((longlong)puVar1 + 0x6c) = 0;

  if (0xf < (ulonglong)puVar1[0x11]) {

    puVar2 = (undefined8 *)*puVar2;

  }

  puVar1[0x10] = 0;

  *(undefined1 *)puVar2 = 0;

  *(undefined8 *)((longlong)puVar1 + 0x94) = 0;

  FUN_140026370(param_1,puVar1);

  return puVar1;

}




