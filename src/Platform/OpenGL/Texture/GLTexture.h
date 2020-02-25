// Copyright(c) 2019 - 2020, #Momo
// All rights reserved.
// 
// Redistributionand use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met :
// 
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditionsand the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditionsand the following disclaimer in the documentation
// and /or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include "Core/Interfaces/GraphicAPI/Texture.h"

namespace MxEngine
{
	class GLTexture final : public Texture
	{
		size_t width = 0, height = 0, channels = 0;
		mutable IBindable::IdType activeId = 0;
		#ifdef _DEBUG
		unsigned char* texture = nullptr;
		#endif	
		void FreeTexture();
	public:
		GLTexture();
		GLTexture(const GLTexture&) = delete;
		GLTexture(GLTexture&& texture);
		GLTexture(const std::string& filepath, bool genMipmaps = true, bool flipImage = true);
		~GLTexture();

		// Inherited via ITexture
		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual void Load(const std::string& filepath, bool genMipmaps = true, bool flipImage = true) override;
		virtual void Bind(IBindable::IdType id) const override;
		virtual size_t GetWidth() const override;
		virtual size_t GetHeight() const override;
		virtual size_t GetChannelCount() const override;
	};
}