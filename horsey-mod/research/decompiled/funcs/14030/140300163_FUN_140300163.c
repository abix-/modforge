// Address: 0x140300163
// Ghidra name: FUN_140300163
// ============ 0x140300163 FUN_140300163 (size=119) ============


void FUN_140300163(undefined8 param_1,longlong param_2)



{

  uint *puVar1;

  

  if (*(int *)(param_2 + 0x40) != 0) {

    if (*(int *)(param_2 + 0x44) != 0) {

      puVar1 = *(uint **)(param_2 + 0x80);

      *(byte *)((&DAT_1403ff160)[(longlong)(int)*puVar1 >> 6] + 0x38 +

               (ulonglong)(*puVar1 & 0x3f) * 0x48) =

           *(byte *)((&DAT_1403ff160)[(longlong)(int)*puVar1 >> 6] + 0x38 +

                    (ulonglong)(*puVar1 & 0x3f) * 0x48) & 0xfe;

    }

    __acrt_lowio_unlock_fh(**(undefined4 **)(param_2 + 0x80));

  }

  return;

}




