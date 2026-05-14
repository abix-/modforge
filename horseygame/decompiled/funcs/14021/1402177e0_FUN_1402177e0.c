// Address: 0x1402177e0
// Ghidra name: FUN_1402177e0
// ============ 0x1402177e0 FUN_1402177e0 (size=214) ============


longlong FUN_1402177e0(undefined8 *param_1,longlong param_2,ulonglong param_3)



{

  undefined4 uVar1;

  undefined4 *puVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  puVar2 = (undefined4 *)*param_1;

  if (param_3 <= (ulonglong)(*(longlong *)(puVar2 + 0x12) - *(longlong *)(puVar2 + 0x10))) {

    return *(longlong *)(puVar2 + 0xe) + *(longlong *)(puVar2 + 0x10);

  }

  uVar3 = 0;

  do {

    uVar4 = param_3 - uVar3;

    if ((ulonglong)(*(longlong *)(puVar2 + 0x12) - *(longlong *)(puVar2 + 0x10)) <= param_3 - uVar3)

    {

      uVar4 = *(longlong *)(puVar2 + 0x12) - *(longlong *)(puVar2 + 0x10);

    }

    FUN_1402f8e20(uVar3 + param_2,*(longlong *)(puVar2 + 0xe) + *(longlong *)(puVar2 + 0x10),uVar4);

    uVar3 = uVar3 + uVar4;

    if (uVar3 == param_3) {

      return param_2;

    }

    if (*(char *)(puVar2 + 6) != '\0') {

      uVar1 = FUN_14015e760(*puVar2);

      FUN_1402f94c0(uVar3 + param_2,uVar1,param_3 - uVar3);

      return param_2;

    }

    puVar2 = *(undefined4 **)(puVar2 + 8);

  } while (puVar2 != (undefined4 *)0x0);

  FUN_14012e850("Peeking past end of incomplete track");

  return 0;

}




