// Address: 0x140277810
// Ghidra name: FUN_140277810
// ============ 0x140277810 FUN_140277810 (size=127) ============


uint FUN_140277810(longlong param_1)



{

  int iVar1;

  uint uVar2;

  undefined4 *puVar3;

  undefined1 local_48 [64];

  

  puVar3 = (undefined4 *)FUN_1401841a0(1,0x20);

  uVar2 = (uint)puVar3;

  if (puVar3 != (undefined4 *)0x0) {

    *puVar3 = 4000;

    *(undefined4 **)(param_1 + 0x70) = puVar3;

    iVar1 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_48,0x40,0x10);

    uVar2 = 0;

    if (iVar1 != 0) {

      uVar2 = FUN_140277aa0(*(undefined8 *)(param_1 + 0x80));

      if ((char)uVar2 != '\0') {

        FUN_1402083c0(param_1,"Steam Deck");

        uVar2 = FUN_140208110(param_1,0);

        return uVar2;

      }

    }

  }

  return uVar2 & 0xffffff00;

}




