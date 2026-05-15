// Address: 0x140198020
// Ghidra name: FUN_140198020
// ============ 0x140198020 FUN_140198020 (size=475) ============


undefined1

FUN_140198020(char param_1,longlong param_2,longlong param_3,longlong param_4,longlong param_5,

             longlong param_6,longlong param_7)



{

  longlong lVar1;

  undefined1 uVar2;

  char cVar3;

  longlong *plVar4;

  code *pcVar5;

  

  if (param_2 == 0) {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","asyncio");

    return uVar2;

  }

  if (param_3 != 0) {

    if (param_6 == 0) {

      uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","queue");

    }

    else {

      plVar4 = (longlong *)FUN_1401841a0(1,0x88);

      uVar2 = 0;

      if (plVar4 != (longlong *)0x0) {

        *plVar4 = param_2;

        plVar4[3] = param_4;

        plVar4[5] = param_3;

        plVar4[2] = param_6;

        *(uint *)(plVar4 + 1) = (uint)(param_1 == '\0');

        plVar4[8] = param_5;

        plVar4[10] = param_7;

        FUN_140179b40(*(undefined8 *)(param_2 + 0x30));

        if (*(longlong *)(param_2 + 0xc0) == 0) {

          plVar4[0xb] = param_2 + 0x38;

          lVar1 = *(longlong *)(param_2 + 0x98);

          plVar4[0xc] = lVar1;

          if (lVar1 != 0) {

            *(longlong **)(lVar1 + 0x58) = plVar4;

          }

          *(longlong **)(param_2 + 0x98) = plVar4;

          FUN_140138fb0(param_6 + 0x38,1);

          FUN_140179b60(*(undefined8 *)(param_2 + 0x30));

          if (param_1 == '\0') {

            pcVar5 = *(code **)(param_2 + 0x10);

          }

          else {

            pcVar5 = *(code **)(param_2 + 8);

          }

          cVar3 = (*pcVar5)(*(undefined8 *)(param_2 + 0x28),plVar4);

          if (cVar3 == '\0') {

            FUN_140138fb0(param_6 + 0x38,0xffffffff);

            FUN_140179b40(*(undefined8 *)(param_2 + 0x30));

            if (plVar4[0xc] != 0) {

              *(longlong *)(plVar4[0xc] + 0x58) = plVar4[0xb];

            }

            *(longlong *)(plVar4[0xb] + 0x60) = plVar4[0xc];

            plVar4[0xc] = 0;

            plVar4[0xb] = 0;

            FUN_140179b60(*(undefined8 *)(param_2 + 0x30));

            FUN_1401841e0(plVar4);

            plVar4 = (longlong *)0x0;

          }

          uVar2 = plVar4 != (longlong *)0x0;

        }

        else {

          FUN_1401841e0(plVar4);

          FUN_140179b60(*(undefined8 *)(param_2 + 0x30));

          uVar2 = FUN_14012e850("SDL_AsyncIO is closing, can\'t start new tasks");

        }

      }

    }

    return uVar2;

  }

  uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_14033af30);

  return uVar2;

}




