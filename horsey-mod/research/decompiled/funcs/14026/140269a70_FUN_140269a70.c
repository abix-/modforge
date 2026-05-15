// Address: 0x140269a70
// Ghidra name: FUN_140269a70
// ============ 0x140269a70 FUN_140269a70 (size=11) ============


ulonglong FUN_140269a70(longlong *param_1)



{

  char cVar1;

  int iVar2;

  uint uVar3;

  ulonglong in_RAX;

  

  if (*(char *)((longlong)param_1 + 0x24) != '\0') {

    return in_RAX;

  }

  iVar2 = FUN_140138fe0(*param_1 + 0x88);

  if (0 < iVar2) {

    return 0;

  }

  uVar3 = FUN_140193800(*(undefined8 *)(*param_1 + 0x80),param_1 + 8,0x40,0);

  if (((0 < (int)uVar3) && ((char)param_1[2] == '\0')) &&

     (*(char *)((longlong)param_1 + 0x24) == '\0')) {

    cVar1 = (char)param_1[8];

    if (((cVar1 == '0') || (cVar1 == '1')) || (cVar1 == '?')) {

      *(char *)((longlong)param_1 + 0x24) = cVar1;

    }

  }

  return (ulonglong)uVar3;

}




