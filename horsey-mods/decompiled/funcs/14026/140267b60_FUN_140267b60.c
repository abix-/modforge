// Address: 0x140267b60
// Ghidra name: FUN_140267b60
// ============ 0x140267b60 FUN_140267b60 (size=337) ============


undefined8 FUN_140267b60(undefined8 *param_1)



{

  char cVar1;

  undefined8 uVar2;

  

  if (((*(byte *)((longlong)param_1 + 0x14c) & 0x80) != 0) &&

     (cVar1 = FUN_140267e80(param_1,5,0,&DAT_14037e330,0xf), cVar1 == '\0')) {

    return 0;

  }

  cVar1 = FUN_1402651d0(param_1);

  if (cVar1 == '\0') {

    return 0;

  }

  cVar1 = FUN_140267e50(param_1,0);

  if (cVar1 != '\0') {

    *(undefined4 *)(param_1 + 0x1c) = 0;

    cVar1 = FUN_140267b10(param_1,1,0x14);

    if (cVar1 == '\0') {

      return 0;

    }

    cVar1 = FUN_1402680b0(param_1,6,0);

    if ((cVar1 != '\0') && ((*(byte *)((longlong)param_1 + 0x14c) & 0x10) == 0)) {

      FUN_140267e80(param_1);

    }

    cVar1 = FUN_1402680e0(param_1,10,0);

    if (cVar1 != '\0') {

      FUN_140267ef0();

    }

    cVar1 = FUN_1402680e0(param_1,0,0);

    if (cVar1 != '\0') {

      FUN_140267ef0();

    }

    if (((*(char *)(param_1 + 1) == '\0') || (cVar1 = FUN_140265160(param_1), cVar1 != '\0')) &&

       (*(int *)((longlong)param_1 + 0xc) == 0)) {

      uVar2 = FUN_140208110(*(undefined8 *)*param_1,(longlong)param_1 + 0xc);

      return uVar2;

    }

    if ((*(int *)((longlong)param_1 + 0x144) == 5) && (*(int *)(param_1 + 2) == 0)) {

      *(int *)(param_1 + 2) = (int)param_1;

      FUN_140182e30((ulonglong)param_1 & 0xffffffff,"Xbox One Chatpad");

    }

    return 1;

  }

  return 0;

}




