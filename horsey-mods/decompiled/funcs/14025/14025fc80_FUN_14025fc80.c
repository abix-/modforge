// Address: 0x14025fc80
// Ghidra name: FUN_14025fc80
// ============ 0x14025fc80 FUN_14025fc80 (size=260) ============


undefined8 FUN_14025fc80(longlong param_1,int param_2,int param_3,undefined4 param_4)



{

  char cVar1;

  undefined8 uVar2;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 == '\0') {

    uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_DrawPoint(): dst");

  }

  else if (*(byte *)(*(longlong *)(param_1 + 0x38) + 4) < 8) {

    uVar2 = FUN_14012e850("SDL_DrawPoint(): Unsupported surface format");

  }

  else {

    if ((((*(int *)(param_1 + 100) <= param_2) && (*(int *)(param_1 + 0x68) <= param_3)) &&

        (param_2 < *(int *)(param_1 + 100) + *(int *)(param_1 + 0x6c))) &&

       (param_3 < *(int *)(param_1 + 0x70) + *(int *)(param_1 + 0x68))) {

      cVar1 = *(char *)(*(longlong *)(param_1 + 0x38) + 5);

      if (cVar1 == '\x01') {

        *(char *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + *(longlong *)(param_1 + 0x18) +

                 (longlong)param_2) = (char)param_4;

      }

      else if (cVar1 == '\x02') {

        *(short *)((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 2) +

                  *(longlong *)(param_1 + 0x18)) = (short)param_4;

      }

      else {

        if (cVar1 == '\x03') {

          uVar2 = FUN_14012e850("That operation is not supported");

          return uVar2;

        }

        if (cVar1 == '\x04') {

          *(undefined4 *)

           ((longlong)(param_3 * *(int *)(param_1 + 0x10)) + (longlong)(param_2 * 4) +

           *(longlong *)(param_1 + 0x18)) = param_4;

        }

      }

    }

    uVar2 = 1;

  }

  return uVar2;

}




