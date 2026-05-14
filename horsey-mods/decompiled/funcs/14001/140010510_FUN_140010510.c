// Address: 0x140010510
// Ghidra name: FUN_140010510
// ============ 0x140010510 FUN_140010510 (size=48) ============


ulonglong FUN_140010510(undefined8 param_1,longlong param_2,longlong param_3)



{

  short sVar1;

  ushort uVar2;

  

  sVar1 = *(short *)(param_2 + 0x38);

  if ((sVar1 == *(short *)(param_3 + 0x38)) && (sVar1 != 0)) {

    return (ulonglong)CONCAT11((char)((ushort)sVar1 >> 8),0 < sVar1);

  }

  uVar2 = *(ushort *)(param_2 + 0x36);

  if (((*(ushort *)(param_3 + 0x34) & uVar2) != 0) &&

     (uVar2 = *(ushort *)(param_3 + 0x36), (*(ushort *)(param_2 + 0x34) & uVar2) != 0)) {

    return CONCAT71((uint7)(byte)(uVar2 >> 8),1);

  }

  return (ulonglong)uVar2 & 0xffffffffffffff00;

}




