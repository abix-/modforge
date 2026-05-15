// Address: 0x140220d20
// Ghidra name: FUN_140220d20
// ============ 0x140220d20 FUN_140220d20 (size=348) ============


undefined2 * FUN_140220d20(HGLOBAL param_1,longlong *param_2)



{

  longlong lVar1;

  uint uVar2;

  SIZE_T SVar3;

  uint *puVar4;

  longlong lVar5;

  undefined2 *puVar6;

  

  lVar5 = 0;

  puVar6 = (undefined2 *)0x0;

  SVar3 = GlobalSize(param_1);

  if (SVar3 < 0x29) {

    FUN_14012e850("Invalid BMP data");

    return (undefined2 *)0x0;

  }

  puVar4 = GlobalLock(param_1);

  if (puVar4 == (uint *)0x0) {

    FUN_1401a9ed0("GlobalLock()");

    return (undefined2 *)0x0;

  }

  uVar2 = puVar4[4];

  if (uVar2 == 0) {

    if (*(ushort *)((longlong)puVar4 + 0xe) < 9) {

      uVar2 = puVar4[8];

      if (uVar2 == 0) {

        uVar2 = 1 << ((byte)*(ushort *)((longlong)puVar4 + 0xe) & 0x1f);

      }

      lVar5 = (ulonglong)uVar2 << 2;

    }

  }

  else if (uVar2 == 3) {

    lVar5 = 0xc;

  }

  else if (uVar2 == 6) {

    lVar5 = 0x10;

  }

  else {

    lVar5 = (ulonglong)puVar4[8] << 2;

  }

  if (SVar3 < (ulonglong)*puVar4 + (ulonglong)puVar4[5] + lVar5) {

    FUN_14012e850("Invalid BMP data");

  }

  else {

    lVar1 = SVar3 + 0xe;

    puVar6 = (undefined2 *)FUN_1401841f0(lVar1);

    if (puVar6 != (undefined2 *)0x0) {

      *puVar6 = 0x4d42;

      *(int *)(puVar6 + 1) = (int)lVar1;

      *(undefined4 *)(puVar6 + 3) = 0;

      *(uint *)(puVar6 + 5) = *puVar4 + 0xe + (int)lVar5;

      FUN_1402f8e20(puVar6 + 7,puVar4,SVar3);

      *param_2 = lVar1;

    }

  }

  GlobalUnlock(param_1);

  return puVar6;

}




