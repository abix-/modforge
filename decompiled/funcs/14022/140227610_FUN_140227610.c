// Address: 0x140227610
// Ghidra name: FUN_140227610
// ============ 0x140227610 FUN_140227610 (size=255) ============


HCURSOR FUN_140227610(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  HCURSOR hCursor;

  float *pfVar5;

  float fVar6;

  

  fVar6 = DAT_14039ca44;

  lVar1 = *(longlong *)(param_1 + 8);

  cVar2 = FUN_140142940("SDL_MOUSE_DPI_SCALE_CURSORS",0);

  if (cVar2 != '\0') {

    uVar4 = FUN_140161230();

    uVar3 = FUN_14016d540(uVar4);

    fVar6 = (float)FUN_14016d370(uVar3);

    if (fVar6 == 0.0) {

      fVar6 = DAT_14039ca44;

    }

  }

  for (pfVar5 = *(float **)(lVar1 + 8); pfVar5 != (float *)0x0; pfVar5 = *(float **)(pfVar5 + 4)) {

    if (fVar6 == *pfVar5) {

      return *(HCURSOR *)(pfVar5 + 2);

    }

  }

  hCursor = (HCURSOR)FUN_140227cc0(lVar1 + 0x20,*(undefined4 *)(lVar1 + 0x18),

                                   *(undefined4 *)(lVar1 + 0x10),*(undefined4 *)(lVar1 + 0x14),fVar6

                                  );

  if (hCursor != (HCURSOR)0x0) {

    pfVar5 = (float *)FUN_1401841a0(1,0x18);

    if (pfVar5 != (float *)0x0) {

      *pfVar5 = fVar6;

      *(HCURSOR *)(pfVar5 + 2) = hCursor;

      *(undefined8 *)(pfVar5 + 4) = *(undefined8 *)(lVar1 + 8);

      *(float **)(lVar1 + 8) = pfVar5;

      return hCursor;

    }

    DestroyCursor(hCursor);

  }

  return (HCURSOR)0x0;

}




