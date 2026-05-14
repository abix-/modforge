// Address: 0x1401676f0
// Ghidra name: FUN_1401676f0
// ============ 0x1401676f0 FUN_1401676f0 (size=110) ============


void FUN_1401676f0(undefined8 *param_1)



{

  if (param_1 != (undefined8 *)0x0) {

    FUN_1401747e0(*(undefined4 *)(param_1 + 1));

    FUN_14015ce70(param_1);

    if (*(char *)(param_1 + 0x17) == '\0') {

      FUN_14015fa70(param_1);

    }

    else if ((undefined4 *)param_1[0x18] != (undefined4 *)0x0) {

      FUN_14015ddd0(*(undefined4 *)param_1[0x18]);

    }

    FUN_140190140(param_1[0x15]);

    FUN_140217cf0(param_1[0xc]);

    FUN_140179b30(*param_1);

    FUN_1401841e0(param_1);

  }

  return;

}




