// Address: 0x140162b40
// Ghidra name: FUN_140162b40
// ============ 0x140162b40 FUN_140162b40 (size=150) ============


undefined8 FUN_140162b40(longlong *param_1)



{

  longlong *plVar1;

  undefined8 *puVar2;

  longlong lVar3;

  undefined8 uVar4;

  

  lVar3 = FUN_1401611a0();

  if (param_1 != *(longlong **)(lVar3 + 0x120)) {

    if (param_1 != (longlong *)0x0) {

      if (param_1 != *(longlong **)(lVar3 + 0x118)) {

        plVar1 = *(longlong **)(lVar3 + 0x110);

        while( true ) {

          if (plVar1 == (longlong *)0x0) {

            uVar4 = FUN_14012e850("Cursor not associated with the current mouse");

            return uVar4;

          }

          if (plVar1 == param_1) break;

          plVar1 = (longlong *)plVar1[2];

        }

      }

      puVar2 = (undefined8 *)*param_1;

      if (puVar2 != (undefined8 *)0x0) {

        *(undefined4 *)((longlong)puVar2 + 0xc) = 0;

        uVar4 = FUN_140149350();

        *puVar2 = uVar4;

      }

      *(longlong **)(lVar3 + 0x120) = param_1;

    }

    FUN_140162700();

  }

  return 1;

}




