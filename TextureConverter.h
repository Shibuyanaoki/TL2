#pragma once
#include <string>
#include "Extemal/DirectXTex/DirectXTex.h"

class TextureConverter
{
private:

	void LoadWICTextureFromFIle(const std::string& filePath);

	std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	/// <summary>
	/// �t�H���_�[�p�X�ƃt�@�C�����𕪗�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void SeparateFilePath(const std::wstring& filePath);

	// �摜�̏��
	DirectX::TexMetadata metadata_;

	// �摜�̃C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;

	// �f�B���N�g���p�X
	std::wstring directoryPath_;

	// �t�@�C����
	std::wstring fileName_;

	// �t�@�C���g���q
	std::wstring fileExt_;

public:

	/// <summary>
/// �e�N�X�`����WIC����DDS�ɕϊ�
/// </summary>
/// <param name="filePath">�t�@�C���p�X</param>
	void ConvertTextureWICToDDS(const std::string& filePath);

};

