#pragma once
#include <string>
class TextureConverter
{
private:

	std::wstring ConvertMultiByteStringToWideString(const std::string& mString);



public:

	/// <summary>
	/// テクスチャをWICからDDSに変換
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& mString);


	

};

