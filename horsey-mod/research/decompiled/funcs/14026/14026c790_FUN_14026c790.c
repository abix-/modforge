// Address: 0x14026c790
// Ghidra name: FUN_14026c790
// ============ 0x14026c790 FUN_14026c790 (size=126) ============


int FUN_14026c790(longlong *param_1)



{

  char cVar1;

  int iVar2;

  

  iVar2 = FUN_140138fe0(*param_1 + 0x88);

  if (0 < iVar2) {

    return 0;

  }

  iVar2 = FUN_140193800(*(undefined8 *)(*param_1 + 0x80),param_1 + 8,0x40,0);

  if (((0 < iVar2) && ((char)param_1[2] == '\0')) && (*(char *)((longlong)param_1 + 0x24) == '\0'))

  {

    cVar1 = (char)param_1[8];

    if (((cVar1 == '0') || (cVar1 == '1')) || (cVar1 == '?')) {

      *(char *)((longlong)param_1 + 0x24) = cVar1;

    }

  }

  return iVar2;

}




