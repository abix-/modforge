// Address: 0x14018fd40
// Ghidra name: FUN_14018fd40
// ============ 0x14018fd40 FUN_14018fd40 (size=256) ============


void FUN_14018fd40(int param_1,code *param_2,undefined8 param_3,undefined4 param_4)



{

  int iVar1;

  longlong lVar2;

  

  if (param_2 != (code *)0x0) {

    lVar2 = FUN_140174d30(param_4,"SDL.filedialog.filters",0);

    iVar1 = FUN_140174c40(param_4,"SDL.filedialog.nfilters",0xffffffffffffffff);

    if ((lVar2 == 0) || (iVar1 != -1)) {

      lVar2 = FUN_14022fd50(lVar2,iVar1);

      if (lVar2 == 0) {

        if (((param_1 == 0) || (param_1 == 1)) || (param_1 == 2)) {

          FUN_14022e060(param_1,param_2,param_3,param_4);

        }

        else {

          FUN_14012e850("Unsupported file dialog type: %d",param_1);

          (*param_2)(param_3,0,0xffffffff);

        }

      }

      else {

        FUN_14012e850("Invalid dialog file filters: %s",lVar2);

        (*param_2)(param_3,0,0xffffffff);

      }

    }

    else {

      FUN_14012e850(

                   "Set filter pointers, but didn\'t set number of filters (SDL_PROP_FILE_DIALOG_NFILTERS_NUMBER)"

                   );

      (*param_2)(param_3,0,0xffffffff);

    }

  }

  return;

}




