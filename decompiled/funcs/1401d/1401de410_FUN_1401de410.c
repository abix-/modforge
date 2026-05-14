// Address: 0x1401de410
// Ghidra name: FUN_1401de410
// ============ 0x1401de410 FUN_1401de410 (size=123) ============


bool FUN_1401de410(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong lVar2;

  char cVar3;

  

  lVar1 = *(longlong *)(param_2 + 0x138);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 == 0) {

    return true;

  }

  cVar3 = FUN_1401de490(*(undefined8 *)(lVar2 + 0x10),lVar1);

  if (cVar3 != '\0') {

    if (*(char *)(lVar1 + 0x48) == '\0') {

      return true;

    }

    cVar3 = FUN_1401de490(*(undefined8 *)(lVar2 + 0x10),lVar1 + 0x50);

    if (cVar3 != '\0') {

      cVar3 = FUN_1401de490(*(undefined8 *)(lVar2 + 0x10),lVar1 + 0x78);

      return cVar3 != '\0';

    }

  }

  return false;

}




