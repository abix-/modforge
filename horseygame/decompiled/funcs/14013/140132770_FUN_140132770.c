// Address: 0x140132770
// Ghidra name: FUN_140132770
// ============ 0x140132770 FUN_140132770 (size=210) ============


longlong * FUN_140132770(longlong param_1)



{

  longlong *plVar1;

  

  if (param_1 == 0) {

    FUN_14012e850("Invalid GPU device");

  }

  else {

    plVar1 = (longlong *)(**(code **)(param_1 + 0x230))();

    if (plVar1 != (longlong *)0x0) {

      *plVar1 = param_1;

      plVar1[1] = (longlong)plVar1;

      plVar1[0x16] = (longlong)plVar1;

      plVar1[0x1f] = (longlong)plVar1;

      if (*(char *)(param_1 + 0x2ac) != '\0') {

        *(undefined1 *)(plVar1 + 2) = 0;

        plVar1[0xd] = 0;

        *(undefined1 *)(plVar1 + 0x17) = 0;

        plVar1[0x18] = 0;

        *(undefined1 *)(plVar1 + 0x20) = 0;

        *(undefined2 *)(plVar1 + 0x21) = 0;

        *(undefined1 *)((longlong)plVar1 + 0x10a) = 0;

        plVar1[0xe] = 0;

        plVar1[0xf] = 0;

        plVar1[0x10] = 0;

        plVar1[0x11] = 0;

        plVar1[0x12] = 0;

        plVar1[0x13] = 0;

        plVar1[0x14] = 0;

        plVar1[0x15] = 0;

        plVar1[0x19] = 0;

        plVar1[0x1a] = 0;

        plVar1[0x1b] = 0;

        plVar1[0x1c] = 0;

        plVar1[0x1d] = 0;

        plVar1[0x1e] = 0;

      }

      return plVar1;

    }

  }

  return (longlong *)0x0;

}




