// Address: 0x140268010
// Ghidra name: FUN_140268010
// ============ 0x140268010 FUN_140268010 (size=155) ============


undefined8 FUN_140268010(longlong *param_1)



{

  longlong lVar1;

  char cVar2;

  undefined8 uVar3;

  

  if ((char)param_1[1] == '\0') {

    *(uint *)((longlong)param_1 + 0x14c) = *(uint *)((longlong)param_1 + 0x14c) | 0x20;

    *(uint *)((longlong)param_1 + 0x5c) = *(uint *)((longlong)param_1 + 0x5c) | 0x80;

    *(undefined4 *)((longlong)param_1 + 0x144) = 0;

    cVar2 = FUN_140159800(*(undefined2 *)(*(longlong *)*param_1 + 0x20),

                          *(undefined2 *)(*(longlong *)*param_1 + 0x22));

    if (cVar2 != '\0') {

      *(uint *)((longlong)param_1 + 0x14c) = *(uint *)((longlong)param_1 + 0x14c) | 1;

    }

  }

  FUN_140266e50(param_1);

  cVar2 = FUN_1402680b0(param_1,0xc,0);

  if (cVar2 != '\0') {

    FUN_140267cc0(param_1,2);

  }

  lVar1 = *param_1;

  *(undefined4 *)(param_1 + 7) = 2;

  *(undefined8 *)(lVar1 + 8) = 0;

  if (*(int *)((longlong)param_1 + 0xc) == 0) {

    uVar3 = FUN_140208110(*(undefined8 *)*param_1);

    return uVar3;

  }

  return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);

}




