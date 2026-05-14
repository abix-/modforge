// Address: 0x1400268e0
// Ghidra name: FUN_1400268e0
// ============ 0x1400268e0 FUN_1400268e0 (size=173) ============


undefined8 * FUN_1400268e0(longlong param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  longlong lVar3;

  

  puVar1 = (undefined8 *)FUN_1402c704c(0x68);

  lVar3 = -1;

  puVar2 = (undefined8 *)(param_1 + 0x38);

  puVar1[1] = 0xffffffffffffffff;

  puVar1[2] = 0;

  puVar1[7] = 0;

  puVar1[8] = 0;

  puVar1[9] = 0;

  puVar1[10] = 0xf;

  *(undefined1 *)(puVar1 + 7) = 0;

  puVar1[3] = 0;

  puVar1[5] = 0;

  puVar1[6] = 0;

  puVar1[0xb] = 0;

  puVar1[0xc] = 0;

  *puVar1 = TiXmlComment::vftable;

  *(undefined4 *)(puVar1 + 4) = 2;

  if (0xf < *(ulonglong *)(param_1 + 0x50)) {

    puVar2 = (undefined8 *)*puVar2;

  }

  do {

    lVar3 = lVar3 + 1;

  } while (*(char *)((longlong)puVar2 + lVar3) != '\0');

  FUN_140027f50();

  puVar1[2] = *(undefined8 *)(param_1 + 0x10);

  puVar1[1] = *(undefined8 *)(param_1 + 8);

  return puVar1;

}




