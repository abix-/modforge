// Address: 0x14028c030
// Ghidra name: FUN_14028c030
// ============ 0x14028c030 FUN_14028c030 (size=275) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_14028c030(char *param_1)



{

  char cVar1;

  int iVar2;

  ushort uVar3;

  int iVar4;

  double dVar5;

  

  cVar1 = *param_1;

  if (cVar1 == '\0') {

    return (ulonglong)(uint)(((*(int *)(param_1 + 4) % 36000) * 0x8000) / 18000);

  }

  if (cVar1 == '\x01') {

    iVar4 = *(int *)(param_1 + 8);

    iVar2 = *(int *)(param_1 + 4);

    if (iVar4 == 0) {

      return (ulonglong)(ushort)(((ushort)(iVar2 >> 0x1f) & 0x8000) + 0x4000);

    }

    if (iVar2 == 0) {

      uVar3 = (ushort)(iVar4 >> 0x1f);

      return (ulonglong)CONCAT22(uVar3,(uVar3 & 0x8000) + 0x8000);

    }

    dVar5 = (double)thunk_FUN_1402e2b70((double)iVar4,(double)iVar2);

    iVar4 = 45000 - (int)(((double)(float)dVar5 * _DAT_1403812c8) / DAT_140333080);

  }

  else {

    if (cVar1 != '\x02') {

      if (cVar1 != '\x03') {

        return 0;

      }

      return 0x4000;

    }

    iVar4 = *(int *)(param_1 + 4) + 9000;

  }

  return (ulonglong)(uint)((iVar4 % 36000) * 0x8000) / 18000 & 0xffff;

}




