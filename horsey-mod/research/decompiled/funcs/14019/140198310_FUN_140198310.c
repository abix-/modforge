// Address: 0x140198310
// Ghidra name: FUN_140198310
// ============ 0x140198310 FUN_140198310 (size=390) ============


undefined1 FUN_140198310(longlong param_1,undefined1 param_2,longlong param_3,longlong param_4)



{

  longlong lVar1;

  undefined1 uVar2;

  char cVar3;

  longlong *plVar4;

  

  if (param_1 == 0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","asyncio");

  }

  else if (param_3 == 0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","queue");

  }

  else {

    FUN_140179b40(*(undefined8 *)(param_1 + 0x30));

    if (*(longlong *)(param_1 + 0xc0) == 0) {

      plVar4 = (longlong *)FUN_1401841a0(1,0x88);

      if (plVar4 != (longlong *)0x0) {

        *plVar4 = param_1;

        *(undefined4 *)(plVar4 + 1) = 2;

        plVar4[10] = param_4;

        plVar4[2] = param_3;

        *(undefined1 *)(plVar4 + 4) = param_2;

        *(longlong **)(param_1 + 0xc0) = plVar4;

        if (*(longlong *)(param_1 + 0x98) == 0) {

          plVar4[0xb] = param_1 + 0x38;

          lVar1 = *(longlong *)(param_1 + 0x98);

          plVar4[0xc] = lVar1;

          if (lVar1 != 0) {

            *(longlong **)(lVar1 + 0x58) = plVar4;

          }

          *(longlong **)(param_1 + 0x98) = plVar4;

          FUN_140138fb0(param_3 + 0x38,1);

          cVar3 = (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),plVar4);

          if (cVar3 == '\0') {

            FUN_140138fb0(param_3 + 0x38,0xffffffff);

            if (plVar4[0xc] != 0) {

              *(longlong *)(plVar4[0xc] + 0x58) = plVar4[0xb];

            }

            *(longlong *)(plVar4[0xb] + 0x60) = plVar4[0xc];

            plVar4[0xc] = 0;

            plVar4[0xb] = 0;

            FUN_1401841e0(plVar4);

            *(undefined8 *)(param_1 + 0xc0) = 0;

            plVar4 = (longlong *)0x0;

          }

        }

      }

      FUN_140179b60(*(undefined8 *)(param_1 + 0x30));

      uVar2 = plVar4 != (longlong *)0x0;

    }

    else {

      FUN_140179b60(*(undefined8 *)(param_1 + 0x30));

      uVar2 = FUN_14012e850("Already closing");

    }

  }

  return uVar2;

}




