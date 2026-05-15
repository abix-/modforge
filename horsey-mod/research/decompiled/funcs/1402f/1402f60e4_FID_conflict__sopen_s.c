// Address: 0x1402f60e4
// Ghidra name: FID_conflict:_sopen_s
// ============ 0x1402f60e4 FID_conflict:_sopen_s (size=50) ============


/* Library Function - Multiple Matches With Different Base Names

    _sopen_s

    _wsopen_s

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



errno_t __cdecl

FID_conflict__sopen_s

          (int *_FileHandle,char *_Filename,int _OpenFlag,int _ShareFlag,int _PermissionMode)



{

  errno_t eVar1;

  

  eVar1 = common_sopen_dispatch<>(_Filename,_OpenFlag,_ShareFlag,_PermissionMode,_FileHandle,1);

  return eVar1;

}




