// Address: 0x140210790
// Ghidra name: FUN_140210790
// ============ 0x140210790 FUN_140210790 (size=116) ============


void FUN_140210790(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,

                  byte param_5)



{

  longlong *plVar1;

  int iVar2;

  longlong *plVar3;

  

  if (param_3 != 0) {

    FUN_140159d30();

    if ((param_5 & 1) != 0) {

      FUN_1402104a0(param_3);

      FUN_14015bb10();

      return;

    }

    iVar2 = 0;

    plVar3 = DAT_1403fd3a0;

    if (0 < DAT_1403fd3a8) {

      while ((plVar1 = (longlong *)*plVar3, plVar1 == (longlong *)0x0 || (*plVar1 != param_3))) {

        iVar2 = iVar2 + 1;

        plVar3 = plVar3 + 1;

        if (DAT_1403fd3a8 <= iVar2) {

          FUN_14015bb10();

          return;

        }

      }

      *(undefined1 *)((longlong)plVar1 + 0x81) = 1;

    }

    FUN_14015bb10();

  }

  return;

}




