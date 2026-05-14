// Address: 0x1400d5d90
// Ghidra name: FUN_1400d5d90
// ============ 0x1400d5d90 FUN_1400d5d90 (size=597) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400d5d90(longlong param_1,char param_2)



{

  float *pfVar1;

  undefined4 uVar2;

  float fVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  char local_68 [4];

  char local_64 [2];

  char local_62;

  undefined1 local_61;

  undefined8 local_60;

  undefined8 local_58;

  undefined8 local_50;

  

  pfVar1 = *(float **)(param_1 + 0x78);

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

       < DAT_1403f3a08) && (FUN_1402c7138(&DAT_1403f3a08), DAT_1403f3a08 == -1)) {

    local_60 = 0;

    local_58 = 7;

    local_50 = 0xf;

    local_68[0] = s_Trailer_14030eb70[0];

    local_68[1] = s_Trailer_14030eb70[1];

    local_68[2] = s_Trailer_14030eb70[2];

    local_68[3] = s_Trailer_14030eb70[3];

    local_64[0] = s_Trailer_14030eb70[4];

    local_64[1] = s_Trailer_14030eb70[5];

    local_62 = s_Trailer_14030eb70[6];

    local_61 = 0;

    DAT_1403f3a04 = FUN_14006fe60(local_68);

    _Init_thread_footer(&DAT_1403f3a08);

  }

  fVar3 = DAT_140303354;

  fVar5 = *(float *)(param_1 + 0x238) + *pfVar1;

  FUN_140071ed0(DAT_1403f3a04,fVar5);

  uVar2 = DAT_1403da840;

  if (*(int *)(param_1 + 0x1c0) == 0) {

    uVar2 = DAT_1403da884;

  }

  FUN_140072640(uVar2);

  FUN_140071ed0(DAT_1403f3a04 + 1,fVar5);

  FUN_1400727d0();

  if (param_2 != '\0') {

    fVar5 = fVar5 + _DAT_14030eb88;

    fVar6 = pfVar1[1] + DAT_14039ca44;

    if (DAT_1403f3550 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = DAT_1403f3550;

      if ((0x1f < DAT_1403f3550 - 1U) && (iVar4 = 0x6b - DAT_1403f3550, DAT_1403f3550 < 0x4b)) {

        iVar4 = 0x20;

      }

    }

    FUN_140071ed0((0x2d < DAT_1403f3550) + 3 + DAT_1403f3a04,fVar5);

    FUN_140071ed0(DAT_1403f3a04 + 5,fVar5,(float)(iVar4 / 2) * fVar3 + fVar6,fVar3,0);

    FUN_140071ed0(DAT_1403f3a04 + 2,fVar5);

    if ((0 < DAT_1403f3550) && (DAT_1403f3550 = DAT_1403f3550 + 1, 0x6b < DAT_1403f3550)) {

      DAT_1403f3550 = 0;

    }

  }

  return;

}




