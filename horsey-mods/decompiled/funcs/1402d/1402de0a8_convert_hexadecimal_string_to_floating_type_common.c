// Address: 0x1402de0a8
// Ghidra name: convert_hexadecimal_string_to_floating_type_common
// ============ 0x1402de0a8 convert_hexadecimal_string_to_floating_type_common (size=172) ============


/* Library Function - Single Match

    enum SLD_STATUS __cdecl __crt_strtox::convert_hexadecimal_string_to_floating_type_common(struct

   __crt_strtox::floating_point_string const & __ptr64,class __crt_strtox::floating_point_value

   const & __ptr64)

   

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual

   Studio 2019 Release */



SLD_STATUS __cdecl

__crt_strtox::convert_hexadecimal_string_to_floating_type_common

          (floating_point_string *param_1,floating_point_value *param_2)



{

  floating_point_string fVar1;

  SLD_STATUS SVar2;

  ulonglong uVar3;

  floating_point_string *pfVar4;

  bool bVar5;

  int iVar6;

  floating_point_string *pfVar7;

  

  uVar3 = 0;

  pfVar4 = param_1 + 8;

  pfVar7 = param_1 + (ulonglong)*(uint *)(param_1 + 4) + 8;

  iVar6 = (-(uint)(param_2[8] != (floating_point_value)0x0) & 0x1d) + 0x17 + *(int *)param_1;

  if (pfVar4 != pfVar7) {

    do {

      if ((-(ulonglong)(param_2[8] != (floating_point_value)0x0) & 0x1fffffff000000) + 0xffffff <

          uVar3) break;

      fVar1 = *pfVar4;

      iVar6 = iVar6 + -4;

      pfVar4 = pfVar4 + 1;

      uVar3 = uVar3 * 0x10 + (ulonglong)(byte)fVar1;

    } while (pfVar4 != pfVar7);

  }

  bVar5 = true;

  while ((pfVar4 != pfVar7 && (bVar5 != false))) {

    fVar1 = *pfVar4;

    pfVar4 = pfVar4 + 1;

    bVar5 = fVar1 == (floating_point_string)0x0;

  }

  SVar2 = FUN_1402dbe90(uVar3,iVar6,CONCAT71((int7)((ulonglong)pfVar4 >> 8),param_1[0x308]),bVar5,

                        param_2);

  return SVar2;

}




